.PHONY: clean All

All:
	@echo "----------Building project:[ master - Debug ]----------"
	@"$(MAKE)" -f  "master.mk"
clean:
	@echo "----------Cleaning project:[ master - Debug ]----------"
	@"$(MAKE)" -f  "master.mk" clean
