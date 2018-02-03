# 323 3-Radix-Sort<br />
CSC 323-32: Project 3.1 <Radix Sort> (C++)<br />
Preston Peck<br />
Due date: Oct. 20, 2016 <br />

**** Algorithm steps for radix sort:<br />

Step 0: inFile <-- open the input file<br />
     0.1: Top <-- create a new stack<br />
Step 1: data <-- read a data from the input file<br />
     1.1: newNode <-- create a new listNode for the data<br />
     1.2: push (Top, newNode) <-- push newNode onto the top of the stack<br />
     1.3: longestStringLength <-- you need to keep tract of string length of the data here<br />
Step 2: repeat step 1 until file is empty<br />
Step 3: print the stack<br />
Step 4: create hashTable[2][tableSize] <br />
Step 5: currentDigit <-- 0<br />
     5.1: currentTable <-- 0<br />
Step 6: node <-- pop from the stack<br />
     6.1: padString (node)<br />
     6.2: val <-- getVal (node, currentDigit)<br />
     6.3: hashIndex <-- hashIndex (val)<br />
     6.4: addTail (hashTable[currentTable][ hashIndex])<br />
Step 7: repeat step 6 until stack is empty<br />
Step 8:  printTable (HashTable[currentTable] <br />
Step 9: currentDigit++<br />
     9.1: currentTable <-- 1<br />
     9.2: previousTable <-- 0<br />
     9.3: currentQueue <-- 0<br />
Step 10: node <-- deleteHead from the currentQueue in<br />
     10.1: hashTable[previousTable][currentQueue]<br />
     10.2: val <-- getVal (node, currentDigit)<br />
     10.3: hashIndex <-- hashIndex (val) <br />
     10.4: addTail (hashTable[currentTable][ hashIndex])<br />
Step 11:  repeat steps 10 until the currentQueue is empty<br />
Step 12: currentQueue ++<br />
Step 13: repeat step 10 to step 12 until currentQueue >= tableSize - 1<br />
Step 14: temp <-- currentTable<br />
     14.1: currentTable <-- previousTable<br />
     14.2: previousTable <-- temp<br />
     14.3: currentQueue <-- 0<br />
Step 15: repeat step 9 to 14 until currentDigit >= longestStringLength<br />
Step 16: print currentTable<br />

INPUT<br />
ccaabb bbaa a aabb zxc<br />
rafael sebastain<br />
jiaxin huan<br />
stacy manuel adolfas<br />
yat casablanca<br />
yishi<br />
zuoping oliver ahmar maaz<br />
angelo ryan philip stefan lawrence<br />
anthony<br />
changjie joe kar kun<br />
edward teng<br />
xiao<br />

OUTPUT<br />
Table [0][97]: casablanca, a, bbaa<br />
Table [0][98]: aabb, ccaabb<br />
Table [0][99]: zxc<br />
Table [0][100]: edward<br />
Table [0][101]: joe, changjie, lawrence<br />
Table [0][103]: teng, zuoping<br />
Table [0][105]: yishi<br />
Table [0][108]: manuel, rafael<br />
Table [0][110]: kun, stefan, ryan, huan, jiaxin, sebastain<br />
Table [0][111]: xiao, angelo<br />
Table [0][112]: philip<br />
Table [0][114]: kar, ahmar, oliver<br />
Table [0][115]: adolfas<br />
Table [0][116]: yat<br />
Table [0][121]: anthony, stacy<br />
Table [0][122]: maaz<br />

Table [1][32]: a<br />
Table [1][97]: bbaa, stefan, ryan, huan, xiao, kar, ahmar, adolfas, yat, maaz<br />
Table [1][98]: aabb, ccaabb<br />
Table [1][99]: casablanca, lawrence, stacy<br />
Table [1][101]: manuel, rafael, oliver<br />
Table [1][104]: yishi<br />
Table [1][105]: changjie, jiaxin, sebastain, philip<br />
Table [1][108]: angelo<br />
Table [1][110]: teng, zuoping, anthony<br />
Table [1][111]: joe<br />
Table [1][114]: edward<br />
Table [1][117]: kun<br />
Table [1][120]: zxc<br />

Table [0][32]: a<br />
Table [0][97]: maaz, aabb, ccaabb, stacy, rafael, sebastain, edward<br />
Table [0][98]: bbaa<br />
Table [0][101]: angelo, teng<br />
Table [0][102]: stefan, adolfas<br />
Table [0][105]: xiao, zuoping<br />
Table [0][106]: changjie, joe<br />
Table [0][107]: kar, kun<br />
Table [0][108]: philip<br />
Table [0][109]: ahmar<br />
Table [0][110]: casablanca, lawrence<br />
Table [0][111]: anthony<br />
Table [0][115]: yishi<br />
Table [0][117]: huan, manuel<br />
Table [0][118]: oliver<br />
Table [0][120]: jiaxin<br />
Table [0][121]: ryan, yat<br />
Table [0][122]: zxc<br />

Table [1][32]: a, joe, kar, kun, yat, zxc<br />
Table [1][97]: aabb, ccaabb, casablanca, jiaxin<br />
Table [1][98]: bbaa<br />
Table [1][101]: stefan, lawrence<br />
Table [1][102]: rafael<br />
Table [1][103]: angelo, changjie<br />
Table [1][104]: ahmar, anthony, huan<br />
Table [1][105]: philip, yishi, oliver<br />
Table [1][108]: adolfas<br />
Table [1][109]: maaz<br />
Table [1][110]: manuel<br />
Table [1][112]: zuoping<br />
Table [1][114]: ryan<br />
Table [1][116]: stacy, sebastain, teng<br />
Table [1][119]: edward<br />
Table [1][120]: xiao<br />

Table [0][32]: a, joe, kar, kun, yat, zxc, aabb, bbaa, huan, maaz, ryan, teng, xiao<br />
Table [0][97]: rafael, ahmar, manuel<br />
Table [0][99]: ccaabb<br />
Table [0][100]: edward<br />
Table [0][104]: philip<br />
Table [0][105]: jiaxin<br />
Table [0][108]: casablanca, oliver<br />
Table [0][110]: angelo, changjie<br />
Table [0][111]: adolfas, zuoping<br />
Table [0][114]: lawrence<br />
Table [0][115]: stacy, sebastain<br />
Table [0][116]: stefan, anthony<br />
Table [0][121]: yishi<br />

Table [1][32]: a, joe, kar, kun, yat, zxc, aabb, bbaa, huan, maaz, ryan, teng, xiao, ahmar, stacy, yishi<br />
Table [1][97]: angelo, changjie, sebastain<br />
Table [1][98]: casablanca<br />
Table [1][99]: ccaabb<br />
Table [1][100]: adolfas<br />
Table [1][101]: edward<br />
Table [1][106]: jiaxin<br />
Table [1][109]: manuel<br />
Table [1][110]: anthony<br />
Table [1][111]: oliver<br />
Table [1][112]: philip<br />
Table [1][114]: rafael<br />
Table [1][115]: stefan<br />
Table [1][117]: zuoping<br />
Table [1][119]: lawrence<br />

Table [0][32]: a, joe, kar, kun, yat, zxc, aabb, bbaa, huan, maaz, ryan, teng, xiao, ahmar, stacy, yishi, angelo, ccaabb, edward, jiaxin, manuel, oliver, philip, rafael, stefan<br />
Table [0][97]: casablanca, adolfas, anthony, lawrence<br />
Table [0][98]: sebastain<br />
Table [0][104]: changjie<br />
Table [0][122]: zuoping<br />

Table [1][32]: a, joe, kar, kun, yat, zxc, aabb, bbaa, huan, maaz, ryan, teng, xiao, ahmar, stacy, yishi, angelo, ccaabb, edward, jiaxin, manuel, oliver, philip, rafael, stefan, adolfas, anthony, zuoping<br />
Table [1][99]: changjie<br />
Table [1][101]: sebastain<br />
Table [1][108]: lawrence<br />
Table [1][115]: casablanca<br />

Table [0][32]: a, joe, kar, kun, yat, zxc, aabb, bbaa, huan, maaz, ryan, teng, xiao, ahmar, stacy, yishi, angelo, ccaabb, edward, jiaxin, manuel, oliver, philip, rafael, stefan, adolfas, anthony, zuoping, changjie, lawrence<br />
Table [0][97]: casablanca<br />
Table [0][115]: sebastain<br />

Table [1][32]: a, joe, kar, kun, yat, zxc, aabb, bbaa, huan, maaz, ryan, teng, xiao, ahmar, stacy, yishi, angelo, ccaabb, edward, jiaxin, manuel, oliver, philip, rafael, stefan, adolfas, anthony, zuoping, changjie, lawrence, sebastain<br />
Table [1][99]: casablanca<br />
