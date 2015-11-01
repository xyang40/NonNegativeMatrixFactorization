# NonNegativeMatrixFactorization
Detect major events that impact trading volumes for major investment banks:

Background:
https://en.wikipedia.org/wiki/Non-negative_matrix_factorization

The project tries to find hidden events that impact the trading volumes of major investment banks by doing non-negative matrix
factorization.

The data for the tickers are collected from Yahoo! Finance using a Python crawler, which also does data preprocessing.
The core algorithm is implemented using C++ without third-party libraries.

Pay attention if you are to run the program: the amount of data (attached) could be huge and if you run the program as it is,
it may end up taking very long time to finish. I suggest tweaking parameters such as the number of iterations and the 
stop_criterion. Also, you can use the python script to collect ticker data of your own.

Feel free to get in touch if you are interested in what the results turn out to be and would like to know more about my
project.
