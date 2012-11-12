
/* Until a better solution comes along for running emscripten Module multiple time, we'll create it from scratch every run.
   Based on pre/post scripts of  'https://github.com/mdaines/viz.js'
 */

run_web_awk = function(program_source, input_text)
{
	var Module = {
		"noInitialRun": true,

		arguments: [ "-f", "/my_program.awk", "/my_input.txt"],

		reset_outputs: function() {
			Module.awk_stdout = "" ;
			Module.awk_stderr = "" ;
		},
		"preRun": function() {
			FS.createDataFile('/', 'my_program.awk', program_source, true, false);
			FS.createDataFile('/', 'my_input.txt', input_text, true, false);
		},
		"print": function(text) {
			Module.awk_stdout += text + "\n" ;
			//console.log("current stdout = " + Module.awk_stdout);
		},
		"printErr" : function(text) {
			console.log(text);
			Module.awk_stderr += text + "\n";
		},
	};
	//Module["printErr"] = Module["foo_printErr"];

	Module.reset_outputs();

	/* Now comes the emscripten-generated Javascript block ... */

	/* The end of this function is in "post_AWK.js" */
