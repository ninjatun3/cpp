##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=circular_list
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/user/codelite_project/cpp_projects/circular_list
ProjectPath            :=/home/user/codelite_project/cpp_projects/circular_list/circular_list
IntermediateDirectory  :=../build-$(ConfigurationName)/circular_list
OutDir                 :=../build-$(ConfigurationName)/circular_list
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=root
Date                   :=05/11/24
CodeLitePath           :=/root/.codelite
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/circular_list/main.cpp$(ObjectSuffix) ../build-$(ConfigurationName)/circular_list/circ_list.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/circular_list/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/circular_list"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/circular_list"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/circular_list/.d:
	@mkdir -p "../build-$(ConfigurationName)/circular_list"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/circular_list/main.cpp$(ObjectSuffix): main.cpp ../build-$(ConfigurationName)/circular_list/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/codelite_project/cpp_projects/circular_list/circular_list/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/circular_list/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/circular_list/main.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/circular_list/main.cpp$(DependSuffix) -MM main.cpp

../build-$(ConfigurationName)/circular_list/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/circular_list/main.cpp$(PreprocessSuffix) main.cpp

../build-$(ConfigurationName)/circular_list/circ_list.cpp$(ObjectSuffix): circ_list.cpp ../build-$(ConfigurationName)/circular_list/circ_list.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/user/codelite_project/cpp_projects/circular_list/circular_list/circ_list.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/circ_list.cpp$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/circular_list/circ_list.cpp$(DependSuffix): circ_list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/circular_list/circ_list.cpp$(ObjectSuffix) -MF../build-$(ConfigurationName)/circular_list/circ_list.cpp$(DependSuffix) -MM circ_list.cpp

../build-$(ConfigurationName)/circular_list/circ_list.cpp$(PreprocessSuffix): circ_list.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/circular_list/circ_list.cpp$(PreprocessSuffix) circ_list.cpp


-include ../build-$(ConfigurationName)/circular_list//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


