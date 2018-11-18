#define _XOPEN_SOURCE 700
#include "sway/config.h"
#include "sway/commands.h"
#include "sway/input/input-manager.h"
#include "log.h"

struct cmd_results *cmd_keep_kbd_layout(int argc, char **argv) {
	const char *STR_LAYOUT_GLOBAL = "global",
		*STR_LAYOUT_PER_WINDOW = "per_window";
	struct cmd_results *error = NULL;
	if ((error = checkarg(argc, "keep_kbd_layout", EXPECTED_EQUAL_TO, 1))) {
		return error;
	}

	if (!strcmp(argv[0], STR_LAYOUT_GLOBAL)) {
		config->keep_layout = LAYOUT_GLOBAL;
		return cmd_results_new(CMD_SUCCESS, NULL, NULL);
	} else if (!strcmp(argv[0], STR_LAYOUT_PER_WINDOW)) {
		config->keep_layout = LAYOUT_PER_WINDOW;
		return cmd_results_new(CMD_SUCCESS, NULL, NULL);
	} else {
		return cmd_results_new(CMD_FAILURE, "keep_kbd_layout",
							   "Unknown value for keep_kbd_layout");
	}
}
