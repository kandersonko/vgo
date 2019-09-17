# Tree initialization in bison

# 1) separate the non-terminal rules (1000 apart)
A: b C d { $$ = tree(R, 3, $1, $2, $3)}

# 2) 