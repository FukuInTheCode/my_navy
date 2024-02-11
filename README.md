# my_navy

## Module: B-PSU-100 (Grade: N/A)

## Project Description
 Recreation of the famous game 'navy' between two terminal using unix signals

### USAGE
 ./my_navy [player1_pid] map
# Result: 81% (Mark: N/A)
<details>
<summary>Click to expand test results</summary>

### 00 - cheater (100% Passed)
| Test | Status |
| --- | --- |
| Is not a cheater | PASSED |

### 01 - basic signal (100% Passed)
| Test | Status |
| --- | --- |
| Player connection | PASSED |
| Player waiting connection | PASSED |

### 02 - rigor (100% Passed)
| Test | Status |
| --- | --- |
| 2 boats has same length | PASSED |
| Bad boat length | PASSED |
| Bad file path | PASSED |
| Miss argument split | PASSED |
| Miss argument value | PASSED |
| Miss one boat | PASSED |
| Too few arguments | PASSED |
| Wrong argument value | PASSED |

### 02 - rigor - eval (100% Passed)
| Test | Status |
| --- | --- |
| 2 boats has same length | PASSED |
| Bad boat length | PASSED |
| Bad file path | PASSED |
| Miss argument split | PASSED |
| Miss argument value | PASSED |
| Miss one boat | PASSED |
| Too few arguments | PASSED |
| Wrong argument value | PASSED |

### 03 - protocol (75% Passed)
| Test | Status |
| --- | --- |
| Player 1 attack | PASSED |
| Player 1 wait for attack | PASSED |
| Player 2 attack | FAILURE |
| Player 2 wait for attack | PASSED |

### 03 - protocol - eval (100% Passed)
| Test | Status |
| --- | --- |
| Player 1 attack | PASSED |
| Player 1 wait for attack | PASSED |
| Player 2 attack | PASSED |
| Player 2 wait for attack | PASSED |

### 04 - game (62.5% Passed)
| Test | Status |
| --- | --- |
| Attack again after wrong position | FAILURE |
| Attack same position twice | PASSED |
| Attack wrong position 1 | FAILURE |
| Attack wrong position 2 | PASSED |
| Attack wrong position 3 | PASSED |
| Game end | FAILURE |
| Player 1 attack hit | PASSED |
| Player 1 attack missed | PASSED |

### 04 - game - eval (50% Passed)
| Test | Status |
| --- | --- |
| Attack again after wrong position.final.sh | FAILURE |
| Attack same position twice | PASSED |
| Attack wrong position 1 | FAILURE |
| Attack wrong position 2 | PASSED |
| Attack wrong position 3 | PASSED |
| Game end | FAILURE |
| Player 1 attack hit | FAILURE |
| Player 1 attack missed | PASSED |

</details>

## Tests
various maps

