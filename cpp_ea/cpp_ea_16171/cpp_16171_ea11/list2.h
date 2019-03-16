<html>
<head>
<title>~/work/egyetem/lang/pny2/src/ea9_oroklodes/list2.h.html</title>
<meta name="Generator" content="Vim/6.1">
</head>
<body bgcolor="#e5e5e5" text="#000000">
<pre>
<font color="#a52a2a"> 1</font>  <font color="#a020f0">#ifndef LIST_H</font>
<font color="#a52a2a"> 2</font>  <font color="#a020f0">#define LIST_H</font>
<font color="#a52a2a"> 3</font>
<font color="#a52a2a"> 4</font>  <font color="#a020f0">#include </font><span style="background-color: #f2f2f2"><font color="#ff00ff">&lt;iostream&gt;</font></span>
<font color="#a52a2a"> 5</font>
<font color="#a52a2a"> 6</font>  <font color="#2e8b57"><b>class</b></font> list
<font color="#a52a2a"> 7</font>  {
<font color="#a52a2a"> 8</font>  <font color="#a52a2a"><b>public</b></font>:
<font color="#a52a2a"> 9</font>           list();
<font color="#a52a2a">10</font>      <font color="#0000ff">// �k�lszab�ly: polimorfikus oszt�lynak legyen </font>
<font color="#a52a2a">11</font>      <font color="#0000ff">// virtu�lis destruktora!</font>
<font color="#a52a2a">12</font>      <font color="#2e8b57"><b>virtual</b></font>  ~list();
<font color="#a52a2a">13</font>
<font color="#a52a2a">14</font>      list *remove();
<font color="#a52a2a">15</font>      <font color="#2e8b57"><b>void</b></font>  append(list *lp);
<font color="#a52a2a">16</font>      <font color="#2e8b57"><b>void</b></font>  insert(list *lp);
<font color="#a52a2a">17</font>      list *get_next() <font color="#2e8b57"><b>const</b></font> { <font color="#a52a2a"><b>return</b></font> next; }
<font color="#a52a2a">18</font>      list *get_prev() <font color="#2e8b57"><b>const</b></font> { <font color="#a52a2a"><b>return</b></font> prev; }
<font color="#a52a2a">19</font>
<font color="#a52a2a">20</font>      <font color="#0000ff">// virtu�lis f�ggv�ny</font>
<font color="#a52a2a">21</font>      <font color="#2e8b57"><b>virtual</b></font> <font color="#2e8b57"><b>void</b></font> print( std::ostream&amp; os) <font color="#2e8b57"><b>const</b></font>;
<font color="#a52a2a">22</font>
<font color="#a52a2a">23</font>      <font color="#2e8b57"><b>static</b></font> <font color="#2e8b57"><b>int</b></font> get_nid() { <font color="#a52a2a"><b>return</b></font> nid; }
<font color="#a52a2a">24</font>  <font color="#a52a2a"><b>private</b></font>:
<font color="#a52a2a">25</font>      <font color="#2e8b57"><b>const</b></font> <font color="#2e8b57"><b>int</b></font>  id;
<font color="#a52a2a">26</font>            list *prev;
<font color="#a52a2a">27</font>            list *next;
<font color="#a52a2a">28</font>
<font color="#a52a2a">29</font>      <font color="#2e8b57"><b>static</b></font> <font color="#2e8b57"><b>int</b></font> nid;
<font color="#a52a2a">30</font>
<font color="#a52a2a">31</font>      list( <font color="#2e8b57"><b>const</b></font> list &amp;rhs);
<font color="#a52a2a">32</font>      list <font color="#a52a2a"><b>operator</b></font>=( <font color="#2e8b57"><b>const</b></font> list *rhs);
<font color="#a52a2a">33</font>  };
<font color="#a52a2a">34</font>
<font color="#a52a2a">35</font>  std::ostream&amp; <font color="#a52a2a"><b>operator</b></font>&lt;&lt;( std::ostream&amp;, <font color="#2e8b57"><b>const</b></font> list&amp;);
<font color="#a52a2a">36</font>
<font color="#a52a2a">37</font>  <font color="#a020f0">#endif</font> <font color="#0000ff">/*</font><font color="#0000ff"> LIST_H */</font>
<font color="#a52a2a">38</font>
<font color="#a52a2a">39</font>
</pre>
</body>
</html>