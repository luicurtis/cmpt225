#!/usr/bin/env python
import subprocess
import sys, os


def itsover():
    rt = subprocess.call("make -s clean",shell=True);
    sys.exit(1)



numlines = 80
srcfile = "LL.cpp"
passed = 0


# Unbuffered stdout.
sys.stdout = os.fdopen(sys.stdout.fileno(), 'w')
# sys.stdout = os.fdopen(sys.stdout.fileno(), 'w', 0)  -> Python 2


# Copy files & compare
rt = subprocess.call("cp LL.h LL.cpp testdir",shell=True);
os.chdir("testdir")
subprocess.call("head -n %d %s > %s.tmp" % (numlines, srcfile, srcfile),shell=True);
rt = subprocess.call("diff -b -q %s.tmp %s.orig" % (srcfile, srcfile),shell=True);
if rt != 0:
    sys.stdout.write("original algorithms modified\n");
    itsover()


# Compile
rt = subprocess.call("make",shell=True);
if rt != 0:
    sys.stdout.write("compilation failed\n");
    itsover()


# Run test
sys.stdout.write("Running test ... ");
rt = subprocess.call("./x > 1.out",shell=True)
#rt = subprocess.call("timeout 2s ./x > 1.out",shell=True)
if rt == 124:
    sys.stdout.write("ran too long\n");
elif rt:
    sys.stdout.write("program crashed\n");
else:
    rt = subprocess.call("diff -b -q 1.out 1.er &>/dev/null",shell=True);
    if rt == 0:
        sys.stdout.write("passed\n");
    else:
        sys.stdout.write("failed\n");


rt = subprocess.call("make -s clean",shell=True);
sys.exit(0)
