set_global_assignment -entity "myPLL" -library "lib_myPLL" -name IP_TOOL_NAME "altera_pll"
set_global_assignment -entity "myPLL" -library "lib_myPLL" -name IP_TOOL_VERSION "15.1"
set_global_assignment -entity "myPLL" -library "lib_myPLL" -name IP_TOOL_ENV "mwpim"
set_global_assignment -library "lib_myPLL" -name SPD_FILE [file join $::quartus(sip_path) "myPLL.spd"]

set_global_assignment -library "lib_myPLL" -name MISC_FILE [file join $::quartus(sip_path) "myPLL_sim/myPLL.vo"]
