include ../Makefile.inc

SUBDIRS = 9.2-Time_Class_Case_Study \
		  9.5-Time_Class_Case_Study \
	      9.7-When_Constructors_and_Destructors_Are_Called \
          9.8-Returning_a_Reference_or_a_Pointer \
          9.9-Default_Memberwise_Assignment \
          9.10-const_Object_and_const_Member_functions \
	      9.11-Composition_Objects_as_Members_of_Classes \
          9.12-friend_Functions_and_friend_Class

CLEANDIRS = $(SUBDIRS:%=clean-%)
BUILDIRS = $(SUBDIRS:%=build-%)

all: subdirs

subdirs: $(BUILDIRS)
$(BUILDIRS):
	$(MAKE) -C $(@:build-%=%)
	
clean: $(CLEANDIRS)
$(CLEANDIRS):
	$(MAKE) -C $(@:clean-%=%) clean

.PHONY: subdirs $(SUBDIRS) $(CLEANDIRS) $(BUILDIRS)
.PHONY: all clean
