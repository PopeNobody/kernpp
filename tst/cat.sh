#!/bin/bash

set -- "bin/cat.cc" "-v bin/cat.cc"

for args; do
	SR=$(/bin/cat $args )
	LR=$(report ./bin/cat $args )

	if [ "$SR" != "$LR" ]; then

		echo "mismatch:"
		echo "SR:"
		echo "$SR"
		echo "LR:"
		echo "$LR"
		echo
		exit 1
	fi
done
