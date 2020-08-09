#store 1 into r1
00 0 1 0 0 0 0 0 0 01 01 01 # put the sum(1) on alu_q
00 0 1 1 0 0 0 0 0 01 01 01 # setup for store into r1
00 0 1 0 0 0 0 0 0 01 01 01 # complete the store
#store 1 into r2
00 0 1 0 0 0 0 0 0 10 10 10 # put the sum(1) on alu_q
00 0 1 1 0 0 0 0 0 10 10 10 # setup for store into r2
00 0 1 0 0 0 0 0 0 10 10 10 # complete the store 
# r2 = 1
# r1 = 1
00 0 1 0 0 0 0 0 0 01 01 01 # put the sum on alu_q
00 0 1 1 0 0 0 0 0 01 01 01 # setup for store into r1
00 0 1 0 0 0 0 0 0 01 01 01 # complete the store
# r1 = 3
00 0 1 0 0 0 0 0 0 01 01 01 # put the sum on alu_q
00 0 1 1 0 0 0 0 0 01 01 01 # setup for store into r1
00 0 1 0 0 0 0 0 0 01 01 01 # complete the store
# r1 = 7
00 0 1 0 0 0 0 0 0 01 01 01 # put the sum on alu_q
00 0 1 1 0 0 0 0 0 01 01 01 # setup for store into r1
00 0 1 0 0 0 0 0 0 01 01 01 # complete the store
# r1 = F
00 0 1 0 0 0 0 0 0 01 01 01 # put the sum on alu_q
00 0 1 1 0 0 0 0 0 01 01 01 # setup for store into r1
00 0 1 0 0 0 0 0 0 01 01 01 # complete the store: r1 = 1
# r1 = 1F
00 0 1 0 0 0 0 0 0 01 01 01 # put the sum on alu_q
00 0 1 1 0 0 0 0 0 01 01 01 # setup for store into r1
00 0 1 0 0 0 0 0 0 01 01 01 # complete the store: r1 = 1
# r1 = 3F
# add r2 to r1
00 0 0 0 0 0 0 0 0 01 01 10 # put the sum of r1 and r2 on alu_q
00 0 0 1 0 0 0 0 0 01 01 10 # prepare to store alu_q in r1
00 0 0 0 0 0 0 0 0 01 01 10 # complete the store
# r1 = 40
# add r1 and r1 into r3
00 0 0 0 0 0 0 0 0 11 01 01 # put the sum of r1 and r1 on alu_q
00 0 0 1 0 0 0 0 0 11 01 01 # prepare to store alu_q in r3
00 0 0 0 0 0 0 0 0 11 01 01 # complete the store 
# r3 = 80
# add r2 to r1
00 0 0 0 0 0 0 0 0 01 01 10 # put the sum of r1 and r2 on alu_q
00 0 0 1 0 0 0 0 0 01 01 10 # prepare to store alu_q in r1
00 0 0 0 0 0 0 0 0 01 01 10 # complete the store
# r1 = 41
# store r1 into address 80
00 0 0 0 0 1 0 0 0 11 00 11 # prepare to store into mar
00 0 0 0 0 0 0 0 0 11 00 11 # complete the store: mar = 80
00 0 0 0 0 0 0 1 0 11 00 01 # prepare to store into mbr
00 0 0 0 0 0 0 0 0 11 00 01 # complete the store mbr = 41
00 0 0 0 0 0 1 0 0 11 00 01 # prepare to load into mem(80) = 41
00 0 0 0 0 0 0 0 0 11 00 01 # complete the load: mem(80) = 41
# add r2 to r1
00 0 0 0 0 0 0 0 0 01 01 10 # put the sum of r1 and r2 on alu_q
00 0 0 1 0 0 0 0 0 01 01 10 # prepare to store alu_q in r1
00 0 0 0 0 0 0 0 0 01 01 10 # complete the store
# r1 = 42
# add r2 to r3
00 0 0 0 0 0 0 0 0 11 11 10 # put the sum of r3 and r2 on alu_q
00 0 0 1 0 0 0 0 0 11 11 10 # prepare to store alu_q in r3
00 0 0 0 0 0 0 0 0 11 11 10 # complete the store
# r3 = 81 
# store r1 into address r3
00 0 0 0 0 1 0 0 0 11 00 11 # prepare to store into mar
00 0 0 0 0 0 0 0 0 11 00 11 # complete the store: mar = r3
00 0 0 0 0 0 0 1 0 11 00 01 # prepare to store into mbr
00 0 0 0 0 0 0 0 0 11 00 01 # complete the store mbr = r1
00 0 0 0 0 0 1 0 0 11 00 01 # prepare to load into mem(r3) = r1
00 0 0 0 0 0 0 0 0 11 00 01 # complete the load: mem(r3) = r1
# add r2 to r1
00 0 0 0 0 0 0 0 0 01 01 10 # put the sum of r1 and r2 on alu_q
00 0 0 1 0 0 0 0 0 01 01 10 # prepare to store alu_q in r1
00 0 0 0 0 0 0 0 0 01 01 10 # complete the store
# r1 = 43
# add r2 to r3
00 0 0 0 0 0 0 0 0 11 11 10 # put the sum of r3 and r2 on alu_q
00 0 0 1 0 0 0 0 0 11 11 10 # prepare to store alu_q in r3
00 0 0 0 0 0 0 0 0 11 11 10 # complete the store
# r3 = 82
# store r1 into address r3
00 0 0 0 0 1 0 0 0 11 00 11 # prepare to store into mar
00 0 0 0 0 0 0 0 0 11 00 11 # complete the store: mar = r3
00 0 0 0 0 0 0 1 0 11 00 01 # prepare to store into mbr
00 0 0 0 0 0 0 0 0 11 00 01 # complete the store mbr = r1
00 0 0 0 0 0 1 0 0 11 00 01 # prepare to load into mem(r3) = r1
00 0 0 0 0 0 0 0 0 11 00 01 # complete the load: mem(r3) = r1
# add r2 to r1
00 0 0 0 0 0 0 0 0 01 01 10 # put the sum of r1 and r2 on alu_q
00 0 0 1 0 0 0 0 0 01 01 10 # prepare to store alu_q in r1
00 0 0 0 0 0 0 0 0 01 01 10 # complete the store
# r1 = 44
# add r2 to r3
00 0 0 0 0 0 0 0 0 11 11 10 # put the sum of r3 and r2 on alu_q
00 0 0 1 0 0 0 0 0 11 11 10 # prepare to store alu_q in r3
00 0 0 0 0 0 0 0 0 11 11 10 # complete the store
# r3 = 83
# store r1 into address 83
00 0 0 0 0 1 0 0 0 11 00 11 # prepare to store into mar
00 0 0 0 0 0 0 0 0 11 00 11 # complete the store: mar = r3
00 0 0 0 0 0 0 1 0 11 00 01 # prepare to store into mbr
00 0 0 0 0 0 0 0 0 11 00 01 # complete the store mbr = r1
00 0 0 0 0 0 1 0 0 11 00 01 # prepare to load into mem(r3) = r1
00 0 0 0 0 0 0 0 0 11 00 01 # complete the load: mem(r3) = r1
# add r2 to r1
00 0 0 0 0 0 0 0 0 01 01 10 # put the sum of r1 and r2 on alu_q
00 0 0 1 0 0 0 0 0 01 01 10 # prepare to store alu_q in r1
00 0 0 0 0 0 0 0 0 01 01 10 # complete the store
# r1 = 45
# add r2 to r3
00 0 0 0 0 0 0 0 0 11 11 10 # put the sum of r3 and r2 on alu_q
00 0 0 1 0 0 0 0 0 11 11 10 # prepare to store alu_q in r3
00 0 0 0 0 0 0 0 0 11 11 10 # complete the store
# r3 = 84
# store r1 into address 83
00 0 0 0 0 1 0 0 0 11 00 11 # prepare to store into mar
00 0 0 0 0 0 0 0 0 11 00 11 # complete the store: mar = r3
00 0 0 0 0 0 0 1 0 11 00 01 # prepare to store into mbr
00 0 0 0 0 0 0 0 0 11 00 01 # complete the store mbr = r1
00 0 0 0 0 0 1 0 0 11 00 01 # prepare to load into mem(r3) = r1
00 0 0 0 0 0 0 0 0 11 00 01 # complete the load: mem(r3) = r1
# add r2 to r1
00 0 0 0 0 0 0 0 0 01 01 10 # put the sum of r1 and r2 on alu_q
00 0 0 1 0 0 0 0 0 01 01 10 # prepare to store alu_q in r1
00 0 0 0 0 0 0 0 0 01 01 10 # complete the store
# r1 = 46
# add r2 to r3
00 0 0 0 0 0 0 0 0 11 11 10 # put the sum of r3 and r2 on alu_q
00 0 0 1 0 0 0 0 0 11 11 10 # prepare to store alu_q in r3
00 0 0 0 0 0 0 0 0 11 11 10 # complete the store
# r3 = 85
# store r1 into address 83
00 0 0 0 0 1 0 0 0 11 00 11 # prepare to store into mar
00 0 0 0 0 0 0 0 0 11 00 11 # complete the store: mar = r3
00 0 0 0 0 0 0 1 0 11 00 01 # prepare to store into mbr
00 0 0 0 0 0 0 0 0 11 00 01 # complete the store mbr = r1
00 0 0 0 0 0 1 0 0 11 00 01 # prepare to load into mem(r3) = r1
00 0 0 0 0 0 0 0 0 11 00 01 # complete the load: mem(r3) = r1
# add r2 to r1
00 0 0 0 0 0 0 0 0 01 01 10 # put the sum of r1 and r2 on alu_q
00 0 0 1 0 0 0 0 0 01 01 10 # prepare to store alu_q in r1
00 0 0 0 0 0 0 0 0 01 01 10 # complete the store
# r1 = 47
# add r2 to r3
00 0 0 0 0 0 0 0 0 11 11 10 # put the sum of r3 and r2 on alu_q
00 0 0 1 0 0 0 0 0 11 11 10 # prepare to store alu_q in r3
00 0 0 0 0 0 0 0 0 11 11 10 # complete the store
# r3 = 86
# store r1 into address 83
00 0 0 0 0 1 0 0 0 11 00 11 # prepare to store into mar
00 0 0 0 0 0 0 0 0 11 00 11 # complete the store: mar = r3
00 0 0 0 0 0 0 1 0 11 00 01 # prepare to store into mbr
00 0 0 0 0 0 0 0 0 11 00 01 # complete the store mbr = r1
00 0 0 0 0 0 1 0 0 11 00 01 # prepare to load into mem(r3) = r1
00 0 0 0 0 0 0 0 0 11 00 01 # complete the load: mem(r3) = r1
# add r2 to r1
00 0 0 0 0 0 0 0 0 01 01 10 # put the sum of r1 and r2 on alu_q
00 0 0 1 0 0 0 0 0 01 01 10 # prepare to store alu_q in r1
00 0 0 0 0 0 0 0 0 01 01 10 # complete the store
# r1 = 48
# add r2 to r3
00 0 0 0 0 0 0 0 0 11 11 10 # put the sum of r3 and r2 on alu_q
00 0 0 1 0 0 0 0 0 11 11 10 # prepare to store alu_q in r3
00 0 0 0 0 0 0 0 0 11 11 10 # complete the store
# r3 = 87
# store r1 into address 83
00 0 0 0 0 1 0 0 0 11 00 11 # prepare to store into mar
00 0 0 0 0 0 0 0 0 11 00 11 # complete the store: mar = r3
00 0 0 0 0 0 0 1 0 11 00 01 # prepare to store into mbr
00 0 0 0 0 0 0 0 0 11 00 01 # complete the store mbr = r1
00 0 0 0 0 0 1 0 0 11 00 01 # prepare to load into mem(r3) = r1
00 0 0 0 0 0 0 0 0 11 00 01 # complete the load: mem(r3) = r1

