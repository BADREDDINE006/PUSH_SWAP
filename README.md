***This project has been created as part of the 42 curriculum by baharrou***


## Description

The goal of the **PUSH_SWAP** project is to familiarize students with algorithms, specifically sorting algorithms.
In this project, the student is required to sort **stack A** using **stack B** and a specific set of operations. To achieve the maximum score (100%), the program must sort 100 random numbers in fewer than 700 operations, and 500 random numbers in fewer than 5500 operations.


## Instructions

To compile the program, simply run **make**, **make all**, or **make push_swap**.

You can then run the program with typing ./push_swap in your terminal followed by the arguments you want to sort.

To check the number of operations:
```ARG="YOUR ARGUMENTS"; ./push_swap $ARG | wc -l```

To verify if the arguments are sorted correctly:
```ARG="YOUR ARGUMENTS"; ./push_swap $ARG | ./checker_OS $ARG```  (Replace OS with your operating system name: linux or Mac)

*NOTE: before running those commands, make sure it has execution permission by running:*
```chmod +x checker_OS```


## Resources

Here are some resources that will help you understand the project :

- [What is a sorting algorithm](https://www.programiz.com/dsa/sorting-algorithm)

- [Turk algorithm](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)

- [Chunk-based algorithm](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

- [Random number generator](https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php)

Checkers :

- [checker_linux](https://cdn.intra.42.fr/document/document/42886/checker_linux)

- [checker_Mac](https://cdn.intra.42.fr/document/document/42885/checker_Mac)

AI usage :
When I registered for the project, I was confused about which algorithm to use. AI provided me with a list of sorting algorithms and their characteristics, which helped me choose the one I was most comfortable with (the Turk algorithm). AI also helped me correct the linguistic errors in this README.