.global reset
reset:
	ldr sp, =start_top
	bl main
stop: b stop