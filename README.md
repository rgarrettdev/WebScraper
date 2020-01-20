# WebScraper

Compile:
$ gcc –Wall get_links_rg.c string_bs.c –o get_links_rg 
$ gcc –Wall test_links_rg.c string_rg.c –o test_links_rg 

An example on how to execute the program:

$ curl https://curl.haxx.se/docs/manual.html | ./get_links_rg | ./test_links_rg > tested_links_rg.txt


The program (get_links_rg) scrapes a website page for links (anchors) on websites. The ouput is then piped to a second program (test_links_rg) that tests the links scraped for responses and then outputs the repsonses to a text file.
