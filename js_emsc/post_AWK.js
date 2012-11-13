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
