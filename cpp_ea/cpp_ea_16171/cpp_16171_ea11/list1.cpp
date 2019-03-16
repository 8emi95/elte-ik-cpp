<html>
<head>
<title>~/work/egyetem/lang/pny2/src/ea9_oroklodes/list1.cpp.html</title>
<meta name="Generator" content="Vim/6.1">
</head>
<body bgcolor="#e5e5e5" text="#000000">
<pre>
<font color="#a52a2a"> 1</font>  <font color="#a020f0">#include </font><span style="background-color: #f2f2f2"><font color="#ff00ff">&lt;iostream&gt;</font></span>
<font color="#a52a2a"> 2</font>  <font color="#a020f0">#include </font><span style="background-color: #f2f2f2"><font color="#ff00ff">&quot;list1.h&quot;</font></span>
<font color="#a52a2a"> 3</font>
<font color="#a52a2a"> 4</font>  <font color="#a52a2a"><b>using</b></font> <font color="#2e8b57"><b>namespace</b></font> std;
<font color="#a52a2a"> 5</font>
<font color="#a52a2a"> 6</font>  <font color="#0000ff">// statikus membert deklar�lni kell!!</font>
<font color="#a52a2a"> 7</font>  <font color="#2e8b57"><b>int</b></font> list::nid = <span style="background-color: #f2f2f2"><font color="#ff00ff">0</font></span>;
<font color="#a52a2a"> 8</font>
<font color="#a52a2a"> 9</font>  <font color="#0000ff">// inicializ�l� lista</font>
<font color="#a52a2a">10</font>  <font color="#0000ff">// warning-ot ad, mert a mez�k deklar�ci�s sorrendje</font>
<font color="#a52a2a">11</font>  <font color="#0000ff">// a list.h-ban m�st volt. A list.h az els�dleges!</font>
<font color="#a52a2a">12</font>  list::list() : id(nid), prev(<span style="background-color: #f2f2f2"><font color="#ff00ff">0</font></span>), next(<span style="background-color: #f2f2f2"><font color="#ff00ff">0</font></span>)
<font color="#a52a2a">13</font>  {
<font color="#a52a2a">14</font>      ++nid;
<font color="#a52a2a">15</font>  }
<font color="#a52a2a">16</font>
<font color="#a52a2a">17</font>  list::~list()
<font color="#a52a2a">18</font>  {
<font color="#a52a2a">19</font>      remove();
<font color="#a52a2a">20</font>  }
<font color="#a52a2a">21</font>
<font color="#a52a2a">22</font>  list *list::remove()
<font color="#a52a2a">23</font>  {
<font color="#a52a2a">24</font>      <font color="#a52a2a"><b>if</b></font> ( prev ) prev-&gt;next = next;
<font color="#a52a2a">25</font>      <font color="#a52a2a"><b>if</b></font> ( next ) next-&gt;prev = prev;
<font color="#a52a2a">26</font>      next = prev = <span style="background-color: #f2f2f2"><font color="#ff00ff">0</font></span>;
<font color="#a52a2a">27</font>      <font color="#a52a2a"><b>return</b></font> <font color="#a52a2a"><b>this</b></font>;
<font color="#a52a2a">28</font>  }
<font color="#a52a2a">29</font>
<font color="#a52a2a">30</font>  <font color="#2e8b57"><b>void</b></font> list::append( list *lp)
<font color="#a52a2a">31</font>  {
<font color="#a52a2a">32</font>      next = lp-&gt;next;
<font color="#a52a2a">33</font>      lp-&gt;next = <font color="#a52a2a"><b>this</b></font>;
<font color="#a52a2a">34</font>      prev = lp;
<font color="#a52a2a">35</font>      <font color="#a52a2a"><b>if</b></font> ( next ) next-&gt;prev = <font color="#a52a2a"><b>this</b></font>;
<font color="#a52a2a">36</font>  }
<font color="#a52a2a">37</font>
<font color="#a52a2a">38</font>  <font color="#2e8b57"><b>void</b></font> list::insert( list *lp)
<font color="#a52a2a">39</font>  {
<font color="#a52a2a">40</font>      prev = lp-&gt;prev;
<font color="#a52a2a">41</font>      lp-&gt;prev = <font color="#a52a2a"><b>this</b></font>;
<font color="#a52a2a">42</font>      next = lp;
<font color="#a52a2a">43</font>      <font color="#a52a2a"><b>if</b></font> ( prev ) prev-&gt;next = <font color="#a52a2a"><b>this</b></font>;
<font color="#a52a2a">44</font>  }
<font color="#a52a2a">45</font>
<font color="#a52a2a">46</font>  <font color="#2e8b57"><b>void</b></font> list::print( ostream&amp; os) <font color="#2e8b57"><b>const</b></font>
<font color="#a52a2a">47</font>  {
<font color="#a52a2a">48</font>      os &lt;&lt; <span style="background-color: #f2f2f2"><font color="#ff00ff">&quot;[ id = &quot;</font></span> &lt;&lt; id &lt;&lt; <span style="background-color: #f2f2f2"><font color="#ff00ff">&quot; ]&quot;</font></span>;
<font color="#a52a2a">49</font>  }
<font color="#a52a2a">50</font>
<font color="#a52a2a">51</font>  ostream&amp; <font color="#a52a2a"><b>operator</b></font>&lt;&lt;( ostream&amp; os, <font color="#2e8b57"><b>const</b></font> list &amp;l)
<font color="#a52a2a">52</font>  {
<font color="#a52a2a">53</font>      l.print(os);
<font color="#a52a2a">54</font>      <font color="#a52a2a"><b>return</b></font> os;
<font color="#a52a2a">55</font>  }
<font color="#a52a2a">56</font>
<font color="#a52a2a">57</font>
<font color="#a52a2a">58</font>
</pre>
</body>
</html>
