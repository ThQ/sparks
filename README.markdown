# What is it ?

**Sparks** is a [MIT licensed](https://github.com/thomas-quemard/sparks/blob/master/LICENSE) C library for generating PNG [sparklines](http://en.wikipedia.org/wiki/Sparkline) (small
plots) with [Cairo](http://cairographics.org/).

More information :

* http://en.wikipedia.org/wiki/Sparkline



# What you can do

<table>
   <tr>
         <th>Sparkline</th>
         <th>Data</th>
         <th>Source</th>
         <th>Data points</th>
   </tr>

	<tr>
		<td><img src="https://github.com/thq/sparks/raw/master/examples/line.png" /></td>
		<td><a href="https://github.com/thq/sparks/blob/master/examples/line.c">CPU usage</a></td>
      <td></td>
      <td>100</td>
	</tr>

	<tr>
		<td><img src="https://github.com/thq/sparks/raw/master/examples/multi_line.png" /></td>
		<td><a href="https://github.com/thq/sparks/blob/master/examples/multi_line.c">Land temperature (red) and ocean temperature (blue)</a> from 1909 to 2008</td>
      <td><a href="http://www.cru.uea.ac.uk/">CRU</a></td>
      <td>2 x 100</td>
	</tr>
	<tr>
		<td><img src="https://github.com/thq/sparks/raw/master/examples/bars.png" /></td>
		<td><a href="https://github.com/thq/sparks/blob/master/examples/bars.c">Bars</a></td>
      <td></td>
      <td></td>
	</tr>
	<tr>
		<td><img src="https://github.com/thq/sparks/raw/master/examples/area.png" /></td>
		<td><a href="https://github.com/thq/sparks/blob/master/examples/area.c">Japanese suicide rate</a> from 1960 to 2009</td>
      <td><a href="http://www.oecd.org/document/60/0,3746,fr_2649_34631_32368700_1_1_1_1,00&&en-USS_01DBC.html">OECD</a></td>
      <td>50</td>
	</tr>
	<tr>
		<td><img src="https://github.com/thq/sparks/raw/master/examples/line_area.png" /></td>
		<td><a href="https://github.com/thq/sparks/blob/master/examples/line_area.c">Apple closing stock price</a></td>
      <td></td>
      <td>100</td>
	</tr>
</table>
