.PHONY: all
all: style.css

style.css: style.css.h
	$(CC) -MMD -E -P -o $@ $<

-include *.d

.PHONY: clean
clean::
	$(RM) style.css
