#!/usr/bin/env python3

import gi
gi.require_version("My", "0.1.1")
from gi.repository import My

hello = My.Hello(greeting="Hi")
hello.greet("Nate")
