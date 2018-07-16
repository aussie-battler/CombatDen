/*
    Author: Ottavio

    Description:

    A simple task finite state machine.  This FSM just takes a queue
    of BIS_fnc_taskCreate arguments and executes them to completion
    in order.  Each argument in the queue is coupled with an event
    variable.  When the event variable is non-nil, the task is marked
    as successful and the next task is created.  When all the tasks
    are complete the mission ends with success.

    The caller can also pass a queue of failure debriefing class names
    that are coupled with an event variable.  All of the event variables
    in this list are monitored.  If any become non-nil, the mission
    fails using the debriefing class name that the variable is coupled
    with.

    This function must be called with spawn as it does not return until
    the end of the mission.

    Parameter(s):

    0: ARRAY - An array of BIS_fnc_taskCreate arguments and event
    variables.  Each element in the array is an array of the following
    format:
        [[[<arguments to BIS_fnc_taskCreate>],"<event variable name>"], ...]

    1: (Optional) ARRAY - An array of failure debriefing names and event
    variables.  Each element in the array has the following format:
        [[<debriefing class name>, "<event variable>"], ...]

    Returns: true on mission completion

    Example:

    _taskQueue = [
        [[blufor,"FindTask", "Find", "hostageMarker","CREATED",1,true,"move"], "hostageFound"],
        [[blufor,"FreeTask", "Free", objNull,        "CREATED",1,true,"help"], "hostageFree"],
        [[blufor,"exfilTask","Exfil","exfilMarker",  "CREATED",1,true,"move"], "hostageExfil"]
    ];

    [_taskQueue] spawn den_fnc_taskFsm;
*/
params ["_taskQueue", "_failQueue"];

_taskQueue = _this param[0, [], [[]]];
_failQueue = _this param[1, [], [[]]];

_ok   = true;
_head = 0;
_end  = (count _taskQueue);

while {_head < _end && _ok}  do {
    _task      = _taskQueue select _head;
    _taskArgs  = _task select 0;
    _taskEvent = _task select 1;

    _taskArgs call BIS_fnc_taskCreate;

    while {_ok} do {
        if (!isNil _taskEvent) exitWith {
            _taskName = _taskArgs select 1;
            [_taskName, "SUCCEEDED"] call BIS_fnc_taskSetState;
            _head = _head + 1;
            sleep 4;
        };

        {
            _debrief   = _x select 0;
            _failEvent = _x select 1;
            if (!isNil _failEvent) exitWith {
                _ok = false;
                [_debrief, false] call BIS_fnc_endMission;
            };
        } forEach _failQueue;

        sleep 1;
    };
};

if (_ok) then {
    ["end1"] call BIS_fnc_endMission;
};

true;