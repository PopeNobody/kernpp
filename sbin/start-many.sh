for i in 2 3 4 5;
do
  tmux send-keys -t $i $'simchat\n'
done
