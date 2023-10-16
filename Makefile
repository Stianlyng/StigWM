CXX ?= g++
CXXFLAGS += -Wall -Wextra -std=c++11
LDFLAGS += -lX11
PREFIX ?= /usr
BINDIR ?= $(PREFIX)/bin

TARGET = stigwm

SOURCES = WindowManager.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

install: all
	install -Dm755 $(TARGET) $(DESTDIR)$(BINDIR)/$(TARGET)
	mkdir -p /usr/share/xsessions
	echo '[Desktop Entry]' > $(DESTDIR)/usr/share/xsessions/$(TARGET).desktop
	echo 'Name=$(TARGET)' >> $(DESTDIR)/usr/share/xsessions/$(TARGET).desktop
	echo 'Exec=$(DESTDIR)$(BINDIR)/$(TARGET)' >> $(DESTDIR)/usr/share/xsessions/$(TARGET).desktop
	echo 'Type=Application' >> $(DESTDIR)/usr/share/xsessions/$(TARGET).desktop

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/$(TARGET)
	rm -f $(DESTDIR)/usr/share/xsessions/$(TARGET).desktop

clean:
	rm -f $(OBJECTS) $(TARGET)

.PHONY: all install uninstall clean