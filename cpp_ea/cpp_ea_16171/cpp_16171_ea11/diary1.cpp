<html>
<head>
<title>~/work/egyetem/lang/pny2/src/ea9_oroklodes/diary1.cpp.html</title>
<meta name="Generator" content="Vim/6.1">
</head>
<body bgcolor="#e5e5e5" text="#000000">
<pre>
<font color="#a52a2a"> 1</font>  <font color="#a020f0">#include </font><span style="background-color: #f2f2f2"><font color="#ff00ff">&lt;iostream&gt;</font></span>
<font color="#a52a2a"> 2</font>  <font color="#a020f0">#include </font><span style="background-color: #f2f2f2"><font color="#ff00ff">&quot;diary1.h&quot;</font></span>
<font color="#a52a2a"> 3</font>
<font color="#a52a2a"> 4</font>  <font color="#a52a2a"><b>using</b></font> <font color="#2e8b57"><b>namespace</b></font> std;
<font color="#a52a2a"> 5</font>
<font color="#a52a2a"> 6</font>  diary::diary(<font color="#2e8b57"><b>const</b></font> <font color="#2e8b57"><b>char</b></font> *e,<font color="#2e8b57"><b>int</b></font> y,<font color="#2e8b57"><b>int</b></font> m,<font color="#2e8b57"><b>int</b></font> d) : date(y,m,d),event(e) { }
<font color="#a52a2a"> 7</font>
<font color="#a52a2a"> 8</font>  diary::diary(<font color="#2e8b57"><b>const</b></font> <font color="#2e8b57"><b>char</b></font> *e, <font color="#2e8b57"><b>const</b></font> <font color="#2e8b57"><b>char</b></font> *d) : date(d), event(e) { }
<font color="#a52a2a"> 9</font>
<font color="#a52a2a">10</font>  diary::diary(<font color="#2e8b57"><b>const</b></font> <font color="#2e8b57"><b>char</b></font> *e, <font color="#2e8b57"><b>const</b></font> date&amp; dd ) : date(dd), event(e) { }
<font color="#a52a2a">11</font>
<font color="#a52a2a">12</font>  <font color="#2e8b57"><b>void</b></font> diary::print( ostream&amp; os) <font color="#2e8b57"><b>const</b></font>
<font color="#a52a2a">13</font>  {
<font color="#a52a2a">14</font>      list::print(os);
<font color="#a52a2a">15</font>      os &lt;&lt; <span style="background-color: #f2f2f2"><font color="#ff00ff">&quot;, &quot;</font></span>;
<font color="#a52a2a">16</font>      date::print(os);
<font color="#a52a2a">17</font>      os &lt;&lt; <span style="background-color: #f2f2f2"><font color="#ff00ff">&quot;, &quot;</font></span>;
<font color="#a52a2a">18</font>      os &lt;&lt; event;
<font color="#a52a2a">19</font>  }
<font color="#a52a2a">20</font>  ostream&amp; <font color="#a52a2a"><b>operator</b></font>&lt;&lt;( ostream&amp; os, <font color="#2e8b57"><b>const</b></font> diary&amp; d) <font color="#0000ff">// no cpy constr</font>
<font color="#a52a2a">21</font>  {
<font color="#a52a2a">22</font>      d.print(os);
<font color="#a52a2a">23</font>      <font color="#a52a2a"><b>return</b></font> os;
<font color="#a52a2a">24</font>  }
<font color="#a52a2a">25</font>
<font color="#a52a2a">26</font>
</pre>
</body>
</html>