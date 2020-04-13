# Test file for "Lab3_bitManipulation"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
test "PINA: 0x00, PINB: 0x01 => PORTC: 1"
# Set inputs
setPINA 0x00
setPINB 0x01
# Continue for several ticks
continue 5
# Set expect values
expectPORTC 1
# Check pass/fail
checkResult

test "PINA: 0x03, PINB: 0x04 => PORTC: 3" 
setPINA 0x03
setPINB 0x04
continue 5
expectPORTC 3
checkResult

test "PINA: 0x05, PINB: 0x06 => PORTC: 4"
setPINA 0x05
setPINB 0x06
continue 5
expectPORTC 4
checkResult

test "PINA: 0x07, PINB: 0x08 => PORTC: 4"
setPINA 0x07
setPINB 0x08
continue 5
expectPORTC 4
checkResult

test "PINA: 0x09, PINB: 0x0A => PORTC: 4"
setPINA 0x09
setPINB 0x0A
continue 5
expectPORTC 4
checkResult

test "PINA: 0x0B, PINB: 0x0C => PORTC: 5"
setPINA 0x0B
setPINB 0x0C
continue 5
expectPORTC 5
checkResult

test "PINA: 0x0D, PINB: 0x0E => PORTC: 6"
setPINA 0x0D
setPINB 0x0E
continue 5
expectPORTC 6
checkResult

test "PINA: 0x0F, PINB: 0xFF => PORTC: 12"
setPINA 0x0F
setPINB 0xFF
continue 5
expectPORTC 12
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
