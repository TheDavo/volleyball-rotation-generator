.PHONY: clean All

All:
	@echo "----------Building project:[ volleyball_rotation_generator - Debug ]----------"
	@"$(MAKE)" -f  "volleyball_rotation_generator.mk"
clean:
	@echo "----------Cleaning project:[ volleyball_rotation_generator - Debug ]----------"
	@"$(MAKE)" -f  "volleyball_rotation_generator.mk" clean
