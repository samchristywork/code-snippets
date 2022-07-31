#!/bin/bash

usage (){
  echo "Usage: $(basename $0) [pattern] [file ...]"
  exit 1
}

[ "$#" -lt "2" ] && usage

pattern=$1;
shift

movefile=$(mktemp)
echo "#!/bin/bash

# The following operations will be performed:
"> $movefile

for x in "$@"; do
  echo "mv -v -- \"$x\" \"$(echo "$x" | sed "$pattern")\"" >> $movefile
done

$EDITOR $movefile
. $movefile
