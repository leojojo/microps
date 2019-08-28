ping -c 50 google.com | awk -F '[:=]' 'NR>1{print $5}' | grep -Eo '[0-9.]{1,6}' > pingTimes.dat

gnuplot -persist <<-EOFMarker
  set terminal pdfcairo font "Gill Sans,9" linewidth 2 rounded fontscale 1.0
  set output "ping.pdf"
  set ylabel "Time in milliseconds"
  set xlabel "Number of Pings"
  plot "pingTimes.dat" w lp
EOFMarker

mv ping.pdf /mnt/c/Users/setsu/Downloads/
