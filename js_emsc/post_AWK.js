	/* This is the end-part of the wrapping function, defined in "pre_AWK.js" */


	/* Above this point, the entire emscripten-compiled javascript generates and setups the "Module" object.
	   All we need to do is run it */

	var exit_code = Module.run();

	return {
		exit_code: exit_code,
		stderr: Module.awk_stderr,
		stdout: Module.awk_stdout,
		input: input_text,
		program: program_source,
		};
}
