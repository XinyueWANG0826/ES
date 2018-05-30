view wave 
wave clipboard store
wave create -driver freeze -pattern clock -initialvalue 0 -period 100ps -dutycycle 50 -starttime 0ps -endtime 1000ps sim:/counter/clk 
wave create -driver freeze -pattern clock -initialvalue 1 -period 10000ps -dutycycle 1 -starttime 0ps -endtime 10000ps sim:/counter/reset 
wave create -driver freeze -pattern random -initialvalue 0 -period 50ps -random_type Normal -seed 5 -starttime 0ps -endtime 1000ps sim:/counter/enable 
WaveCollapseAll -1
wave clipboard restore
