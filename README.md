# Implémentation d'un réseau de neurones en C++

*"From scratch"*, les **matrices** ici sont utilisés avec une implémentation en template afin de pouvoir être utilisable pour n'importe quel type de données numériques en entrées.
Le C++ est utilisé ici car un des objectifs est de réaliser des benchmarks.

# Guide
    git clone https://github.com/mbenhamd/neural-network-scratch
    cd src/
    git submodule update --init

    # cd into one of the directories above and:
    sh compile.sh
    ./main

# La classe réseau
La fonction d'optimisation utilisée est la descente de gradient (GD).

