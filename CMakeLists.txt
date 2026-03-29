cmake_minimum_required(VERSION 3.25)
project(PO_WildlifeSimulator)

set(CMAKE_CXX_STANDARD 17)

add_executable(PO_WildlifeSimulator main.cpp Simulator.cpp Simulator.h Terminal.cpp Terminal.h World.cpp World.h Organism.h Plant.cpp Plant.h Animal.cpp Animal.h Human.cpp Human.h Wolf.h Sheep.h Fox.cpp Fox.h Tortoise.cpp Tortoise.h Antelope.cpp Antelope.h Grass.h Dandelion.cpp Dandelion.h Guarana.cpp Guarana.h Belladonna.h SosnowskysHogweed.cpp SosnowskysHogweed.h RandomNumberGenerator.cpp RandomNumberGenerator.h VisualInterface.cpp VisualInterface.h VisualInterface.h)
