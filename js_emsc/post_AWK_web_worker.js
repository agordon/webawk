	/* This is the end-part of the wrapping function, defined in "pre_AWK.js" */

	/* Above this point, the entire emscripten-compiled javascript generates and setups the "Module" object.
	   All we need to do is run it */

	Module['__run__'] = run;

	//FS.streams[3].object.printer = Module["foo_printErr"];
	//Module["printErr"] = Module["foo_printErr"];

	var func_run = Module['__run__'];
	var exit_code = func_run();
	var result = {};

	result['exit_code'] = exit_code;
	result['stderr'] = Module.awk_stderr;
	result['stdout'] = Module.awk_stdout;
	result['input'] = input_text ;
	result['program'] = program_source ;

	return result;
}

//NOTE: These values must match the defined enum in awk.c
var NTBT_ENTER_BEGIN_BLOCK= 1;
var NTBT_EXIT_BEGIN_BLOCK = 2;
var NTBT_ENTER_END_BLOCK  = 3;
var NTBT_EXIT_END_BLOCK   = 4;
var NTBT_ENTER_ACTION     = 5;
var NTBT_EXIT_ACTION      = 6;
var NTBT_ENTER_PATTERN    = 7;
var NTBT_TAKE_PATTERN=8; //will only be called if the pattern matched
var NTBT_EXIT_PATTERN=9; //will only be called if the pattern didn't match
var NTBT_IMPLICIT_PATTERN = 10; // called when there's only an action, BEFORE the action notification.
var NTBT_IMPLICIT_ACTION = 11; // called when there's only a pattern, AFTER the pattern notification (only if it matched).
var NTBT_LAST_RULE       = 12; // Last rule means no more patterns/actions - 
var NTBT_NEXT			 = 13; // 'next' called - interrupt flowcontrol
var NTBT_NEXTFILE		 = 14; // 'nextfile' called - interrupt flowcontrol
var NTBT_EXIT			 = 15; // 'exit' called - interrupt flowcontrol
var NTBT_GETLINE		 = 16; // getline was explicitly or implicitly called
var NTBT_END_OF_FILE     = 17; //End of a single file - NOT USED
var NTBT_END_OF_FILES    = 18;  //End of all files - finished program; moving to END block.


var webawk_notification_names = {};
webawk_notification_names[NTBT_ENTER_BEGIN_BLOCK] = "BEGIN(enter)";
webawk_notification_names[NTBT_EXIT_BEGIN_BLOCK]  = "BEGIN(exit)";
webawk_notification_names[NTBT_ENTER_END_BLOCK]   = "END(enter)";
webawk_notification_names[NTBT_EXIT_END_BLOCK]    = "END(exit)";
webawk_notification_names[NTBT_ENTER_ACTION]      = "ACTION(enter)";
webawk_notification_names[NTBT_EXIT_ACTION]       = "ACTION(exit)";
webawk_notification_names[NTBT_ENTER_PATTERN]     = "PATTERN(enter)";
webawk_notification_names[NTBT_TAKE_PATTERN]      = "PATTERN(matched)";
webawk_notification_names[NTBT_EXIT_PATTERN]      = "PATTERN(no-match)"
webawk_notification_names[NTBT_IMPLICIT_PATTERN]  = "PATTERN(implicit)";
webawk_notification_names[NTBT_IMPLICIT_ACTION]   = "ACTION(implicit)";
webawk_notification_names[NTBT_LAST_RULE]         = "LAST_RULE";
webawk_notification_names[NTBT_NEXT]              = "NEXT";
webawk_notification_names[NTBT_NEXTFILE]          = "NEXTFILE";
webawk_notification_names[NTBT_EXIT]              = "EXIT";
webawk_notification_names[NTBT_GETLINE]           = "GETLINE";
webawk_notification_names[NTBT_END_OF_FILE]       = "END_OF_FILE";
webawk_notification_names[NTBT_END_OF_FILES]      = "END_OF_ALL_FILES";

//busy-wait loop sleep is an ugly hack, but we're in a web-worker.
function pausecomp(millis) {
	var date = new Date();
	var curDate = null;

	do { curDate = new Date(); }
	while(curDate-date < millis);
}

function webawk_notification_callback (type,start_line,start_pos,end_line,end_pos)
{
	self.postMessage({
			'event' : 'notification',
			'type' : type,
			'type_name' : webawk_notification_names[type],
			'start_line' : start_line,
			'start_pos'  : start_pos,
			'end_line'   : end_line,
			'end_pos'    : end_pos
			});

	pausecomp(2000);
}

//This is a Web-Worker
self.onmessage = function(event) {
	switch(event.data.type)
	{
	case "run_awk":
		var awk_program = event.data.awk_program;
		var input_data  = event.data.input_data;

		var awk_result = run_web_awk(awk_program, input_data);
		var exit_code = awk_result.exit_code ;

		self.postMessage({
					'event': 'exit',
					'exit_code': exit_code
				});
		break;
	}
};
