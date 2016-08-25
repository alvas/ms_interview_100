# The following command use Makefile to create cpp file from the rest 24 patterns, except AbstractFactory:
# $grep cpp Makefile | tail -n 24 | awk '{print $(NF)}' | xargs touch
#
# The source code example is from https://sourcemaking.com/design_patterns
# creational patterns
CFLAGS = -std=c++11

# In order to compile the AFTER section, instead of BEFORE section, 
# use this command: make METHOD=-DAFTER AbstractFactory
METHOD=-DNORMAL
AbstractFactory:
	g++ $(CFLAGS) $(METHOD) -DSIMPLE AbstractFactory.cpp

Builder:
	g++ $(CFLAGS) Builder.cpp

FactoryMethod:
	g++ $(CFLAGS) $(METHOD) FactoryMethod.cpp

Prototype:
	g++ $(CFLAGS) $(METHOD) Prototype.cpp

Singleton:
	g++ $(CFLAGS) $(METHOD) Singleton.cpp


# structural patterns
Adaptor:
	g++ $(CFLAGS) Adaptor.cpp

Bridge:
	g++ $(CFLAGS) Bridge.cpp

Composite:
	g++ $(CFLAGS) Composite.cpp

Decorator:
	g++ $(CFLAGS) Decorator.cpp

Facade:
	g++ $(CFLAGS) Facade.cpp

Flyweight:
	g++ $(CFLAGS) Flyweight.cpp

Proxy:
	g++ $(CFLAGS) Proxy.cpp


# behavioral patterns
ChainOfResponsibility:
	g++ $(CFLAGS) $(METHOD) ChainOfResponsibility.cpp

Command:
	g++ $(CFLAGS) $(METHOD) Command.cpp

Interpreter:
	g++ $(CFLAGS) $(METHOD) Interpreter.cpp

Iterator:
	g++ $(CFLAGS) $(METHOD) Iterator.cpp

Mediator:
	g++ $(CFLAGS) Mediator.cpp

Memento:
	g++ $(CFLAGS) Memento.cpp

Observer:
	g++ $(CFLAGS) Observer.cpp

State:
	g++ $(CFLAGS) State.cpp

Strategy:
	g++ $(CFLAGS) Strategy.cpp

TemplateMethod:
	g++ $(CFLAGS) TemplateMethod.cpp

Visitor:
	g++ $(CFLAGS) Visitor.cpp
