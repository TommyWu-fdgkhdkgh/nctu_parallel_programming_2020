CXXFLAGS := -g -pthread
CXX := clang++

ifeq ($(VECTORIZE), 1)
  CXXFLAGS += -Rpass=loop-vectorize -Rpass-missed=loop-vectorize -Rpass-analysis=loop-vectorize
endif

a.out: hi.cpp
	$(CXX) $(CXXFLAGS)  hi.cpp	

clean:
	rm -f a.out
