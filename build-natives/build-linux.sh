#!/usr/bin/env bash
premake4 --file=build-linux.lua gmake
make clean config=release64
make config=release64
mv libsteamnetworks4j.so ../java-wrapper/src/main/resources/libsteamnetworks4j.so
mv libsteamnetworks4j-server.so ../server/src/main/resources/libsteamnetworks4j-server.so
mv libsteamnetworks4j-encryptedappticket.so ../server/src/main/resources/libsteamnetworks4j-encryptedappticket.so
