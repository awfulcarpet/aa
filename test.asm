; currently assumes everything has been zero'd
$02
$10
$f0
$1f
$000f
$feab
MVI B,$02
IN $04
INX B ; inc b to 1
INX SP
HLT ; stop cpu
