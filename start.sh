#! /bin/zsh
if [[ $1 == "-b" ]] && then 
    docker build -t proiect-ubuntu . 
elif [[ $1 == "-s" ]] && then
    docker run -it --rm -v $(pwd):/workspace proiect-ubuntu
else
    echo "Nu este un paramatru corect"
fi