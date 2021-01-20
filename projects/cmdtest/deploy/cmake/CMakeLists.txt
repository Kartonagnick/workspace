
# 2020y-08m-17d. WorkSpace project.
# 2020y-08m-24d. WorkSpace project.
# 2020y-12m-21d. WorkSpace project.
# 2021y-01m-15d. WorkSpace project.
################################################################################
################################################################################

set(gDEBUG "$ENV{eDEBUG}")
cmake_minimum_required(VERSION 3.1)

include("${CMAKE_CURRENT_LIST_DIR}/setup.cmake")
cmake_scenario("minimalist")

project(${gNAME_PROJECT} CXX)

################################################################################
################################################################################

make_target()

#--- automatically link with 'mygetst', 'gmock', or 'gtest' 
#--- depending on which libraries are available
make_target(
    PATH_TO_SOURCES "test"
    INCLUDES "${gDIR_SOURCE}/include"
)

################################################################################
################################################################################

