vlib work
vlib DSO
vcom -quiet -work DSO  {../../grlib-W2000A/designs/leon3-w2000a/DSOConfig-p.vhd}
#vcom -quiet -work DSO  {../../grlib-W2000A/designs/leon3-sandboxx/DSOConfig-p.vhd}
vcom -quiet -work DSO {../../Scope/src/Global-p.vhd}
#vcom -quiet -work DSO ../../DownSampler/Octave/FastRampCoeff-p.vhd
#vcom -quiet -work DSO ../../DownSampler/Octave/RampCoeff-p.vhd
vcom -quiet -work DSO ../../DownSampler/Octave/FastFirCoeff-p.vhd
vcom -quiet -work DSO ../../DownSampler/Octave/FirCoeff-p.vhd
vcom -quiet -work DSO ../../DownSampler/src/PolyphaseDecimator-p.vhd
vcom -quiet -work DSO ../../DownSampler/src/FastPolyPhaseDecimator-ea.vhd
vcom -quiet -work DSO ../../DownSampler/src/TopFastPolyPhaseDecimator-ea.vhd
vcom -quiet -work work ../../DownSampler/Octave/ShortInputValues-p.vhd
vcom -quiet -work work ../../DownSampler/src/TestbenchFastPolyPhaseDecimator-ea.vhd
vsim work.Testbench
do wave.do
run -all
