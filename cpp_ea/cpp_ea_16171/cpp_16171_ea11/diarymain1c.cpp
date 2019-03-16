<html>
<head>
<title>~/work/egyetem/lang/pny2/src/ea9_oroklodes/diarymain1c.cpp.html</title>
<meta name="Generator" content="Vim/6.1">
</head>
<body bgcolor="#e5e5e5" text="#000000">
<pre>
<font color="#a52a2a"> 1</font>  <font color="#a020f0">#include </font><span style="background-color: #f2f2f2"><font color="#ff00ff">&lt;iostream&gt;</font></span>
<font color="#a52a2a"> 2</font>  <font color="#a020f0">#include </font><span style="background-color: #f2f2f2"><font color="#ff00ff">&quot;diary1.h&quot;</font></span>
<font color="#a52a2a"> 3</font>
<font color="#a52a2a"> 4</font>  <font color="#a52a2a"><b>using</b></font> <font color="#2e8b57"><b>namespace</b></font> std;
<font color="#a52a2a"> 5</font>
<font color="#a52a2a"> 6</font>  <font color="#2e8b57"><b>int</b></font> main()
<font color="#a52a2a"> 7</font>  {
<font color="#a52a2a"> 8</font>      diary d1( <span style="background-color: #f2f2f2"><font color="#ff00ff">&quot;Tanfolyam kezdete&quot;</font></span>, <span style="background-color: #f2f2f2"><font color="#ff00ff">2000</font></span>, <span style="background-color: #f2f2f2"><font color="#ff00ff">6</font></span>, <span style="background-color: #f2f2f2"><font color="#ff00ff">19</font></span>);
<font color="#a52a2a"> 9</font>      diary d2( <span style="background-color: #f2f2f2"><font color="#ff00ff">&quot;Tanfolyam vege&quot;</font></span>, <span style="background-color: #f2f2f2"><font color="#ff00ff">2000</font></span>, <span style="background-color: #f2f2f2"><font color="#ff00ff">6</font></span>, <span style="background-color: #f2f2f2"><font color="#ff00ff">27</font></span>);
<font color="#a52a2a">10</font>      diary d3( <span style="background-color: #f2f2f2"><font color="#ff00ff">&quot;Pihenes&quot;</font></span>, <span style="background-color: #f2f2f2"><font color="#ff00ff">2000</font></span>, <span style="background-color: #f2f2f2"><font color="#ff00ff">6</font></span>, <span style="background-color: #f2f2f2"><font color="#ff00ff">28</font></span>);
<font color="#a52a2a">11</font>
<font color="#a52a2a">12</font>      <font color="#0000ff">// orvul közbelép a felhasználó:</font>
<font color="#a52a2a">13</font>      list l;
<font color="#a52a2a">14</font>
<font color="#a52a2a">15</font>      d2.append(&amp;d1);
<font color="#a52a2a">16</font>      d3.append(&amp;d2);
<font color="#a52a2a">17</font>      l.append(&amp;d2);
<font color="#a52a2a">18</font>
<font color="#a52a2a">19</font>
<font color="#a52a2a">20</font>      <font color="#a52a2a"><b>for</b></font> ( diary *dp = &amp;d1; dp; dp = (diary*)dp-&gt;get_next() )
<font color="#a52a2a">21</font>  <font color="#0000ff">//    for ( list *lp = &amp;d1; lp; lp = lp-&gt;get_next() ) </font>
<font color="#a52a2a">22</font>      {
<font color="#a52a2a">23</font>           cout &lt;&lt; *dp;   <font color="#0000ff">// runtime error! </font>
<font color="#a52a2a">24</font>           cout &lt;&lt; endl;
<font color="#a52a2a">25</font>      }
<font color="#a52a2a">26</font>      <font color="#a52a2a"><b>return</b></font> <span style="background-color: #f2f2f2"><font color="#ff00ff">0</font></span>;
<font color="#a52a2a">27</font>  }
</pre>
</body>
</html>
