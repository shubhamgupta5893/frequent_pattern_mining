COL 761 - Frequent itemsets mining : assignment - 1



Team consist of -
Sahil Manchanda - 2018CSZ8551
Raj Kamal - 2018CSZ8013
Shubham Gupta - 2019CSZ8470



compile.sh - running it generate executables which will the used by csz188551.sh to generate the frequent item sets and execution time plot of apriori vs fptree.



CSZ188551.sh - 

	./CSZ188551.sh input_file X -apriori <filename> will run apriori algorithm and generate frequent itemsets from input file with minimum support X and save these to filename. 


	./CSZ188551.sh input_file X -fptree <filename> will run fptree algorithm and generate frequent itemsets from input file with minimum support X and save these to filename. 

	./CSZ188551.sh input_file -plot will run apriori and fptree on given dataset with support on [1,5,10,25,50,90] and generate a plot displaying the time of execution vs support. 



fptree.cpp - it implements the algorithm of fp tree based growth pattern mining .
apriori.cpp -it implements the algorithm of apriori based pattern mining.
class_def.h and functions.h includes the common functionality used by both fptree.cpp and apriori.cpp.


existing_result.png - plot of apriori vs fptree execution time, on webdocs.dat data. 


Observation - 
As we can see a very low support 1% and 5%, both algorithms have timed out. At support greater than 5%, it can be seen that fptree is  very fast than apriori. 
One of the reason is that fptree avoid multiple passes over transactios and create a compressed tree representation which can be mined to produce frequent items very fast. 

In Apriori, multiple passes over dataset is required to eliminate infrequent itemsets at ever level of pruning while fptree does only 2 passes to create a compressed representation from which frequent itemsets can be mined quickly. Apriori requires generation of candidate itemsets, from which it mines the frequent ones but in fptree, no candidate generation is required  .At very low support, candidate itemsets in apriori increases exponentially compared to high support. So, running time also increases exponentially in apriori with decrease in threshold. 



Also it seems that memory requirement in fptree sometime is high compared to apriori. 



