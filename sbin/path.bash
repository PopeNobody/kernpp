#!/bin/bash

path() {
  cmd="$1"
  shift
  if [ "x${cmd}" == "xadd" ]; then
    local -n path="$1"
    path=":$path:"
    while path has "$1" "$2"; do
      path="${path/:$2:/:}"
    done
    path=${path%:}
    path=${path#:}
    test -d "$2/" || return 1
    path="$2${path+:$path}"
    eval "export $1"
  elif [ "x${cmd}" == "xhas" ]; then
    local -n path="$1"
    case ":$path:" in
      (*:$2:*) return 0;;
      (*) return 1;;
    esac;
  elif [ "x${cmd}" == "xfix" ]; then
    if test -n "$1" ; then
      eval "$(lspath "$1")"
    fi
  elif [ "x${cmd}" == "xhelp" ]; then
    echo "path cmds:"
    echo "   add:  ads a dir to your that, removes dups"
    echo "   has:  returns true iff dir is on path"
    echo "more to come"
  else
    path help >&2
  fi
}
export -f path

