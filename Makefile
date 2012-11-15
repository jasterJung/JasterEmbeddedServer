
all: 
	make -C thread all
	make -C main all
	#@make -C dri all


clean: 
	@make -C thread clean
	@make -C main clean
	#rm -f lib/* 

rebuild: 
	#@make -C dir rebuild
	#@make -C dir rebuild


