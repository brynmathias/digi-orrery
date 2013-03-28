#!/usr/bin/env python

import glob
import threading
import subprocess
import argparse


gcc = "g++-4.7"
# gcc = "clang++"
CXXFLAGS = " -std=c++11 -Wall -ftree-vectorizer-verbose=4 -Wunsafe-loop-optimizations "
# CXXFLAGS = " -std=c++11 -Wall -g -D_APPLE "
INCDIR = "-I ./include/"
src = "./src/"
obj = "./obj/"

def chunks(l,n):
    """docstring for chunks"""
    return [l[i:i+n] for i in range(0, len(l), n)]
    pass


def makeLib(nameList = None):
    if isinstance(nameList,list):
        for name in nameList:
            if ".cc" in name: name=name[:-3]
            cmd = [gcc + CXXFLAGS + INCDIR + " -c " + name+".cc -shared -o " +obj+name[6:]+".o" ]
            print "Building %s"%name
            subprocess.call(cmd,shell=True)
    
    
def makeMain(mainName):
    if ".cc" in mainName: mainName=mainName[:-3]
    libs = ""
    for x in glob.glob(obj+"*"): libs += " %s "%x
    cmd = [gcc + CXXFLAGS + " -L./obj/ -I./include/ " + src+mainName+".cc "+ libs +" -o ./"+mainName]
    subprocess.call(cmd,shell=True)
    
    
    
def parser():
    parser = argparse.ArgumentParser(description = "Python build script")
    parser.add_argument("--nThreads", type = int, dest="nThreads",default = 3)
    parser.add_argument("--main",type = str, dest = "name", default="")
    parser.add_argument("--clean",type = bool, dest= "clean",default = False)
    args = parser.parse_args()
    
    return args
    


def main():
    args = parser()
    if args.clean:
        for f in glob.glob(obj+"*"):
            subprocess.call(["rm %s"%f],shell=True)
    libList = glob.glob(src+"*.cc")
    for item in libList:
        if args.name in item: libList.remove(item)
    Threads = []
    jList = chunks(libList,int(len(libList)/args.nThreads))
    print jList
    for files in jList:
        Threads.append(threading.Thread(group=None,target=makeLib,args=[files]))
    for t in Threads:
        t.start()
    for t in Threads:
        t.join()
    makeMain(args.name)
    

if __name__ == "__main__":
    main()