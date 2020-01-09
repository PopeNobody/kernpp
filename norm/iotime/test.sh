#!/bin/bash


for i in tmp/*; do
  du -k $i
  dd if=$i of=/dev/null 2>/dev/null
  ./iotime1 < $i;
  ./iotime2 < $i;
  ./iotime3 < $i;
  ./iotime4 < $i
done
