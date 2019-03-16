<html>
<head>
<title>~/work/egyetem/lang/pny2/src/ea9_oroklodes/list2.cpp.html</title>
<meta name="Generator" content="Vim/6.1">
</head>
<body bgcolor="#e5e5e5" text="#000000">
<pre>
<font color="#a020f0">#include </font><span style="background-color: #f2f2f2"><font color="#ff00ff">&lt;iostream&gt;</font></span>
<font color="#a020f0">#include </font><span style="background-color: #f2f2f2"><font color="#ff00ff">&quot;list2.h&quot;</font></span>

<font color="#a52a2a"><b>using</b></font> <font color="#2e8b57"><b>namespace</b></font> std;

<font color="#0000ff">// statikus membert deklarálni kell!!</font>
<font color="#2e8b57"><b>int</b></font> list::nid = <span style="background-color: #f2f2f2"><font color="#ff00ff">0</font></span>;

list::list() : id(nid), prev(<span style="background-color: #f2f2f2"><font color="#ff00ff">0</font></span>), next(<span style="background-color: #f2f2f2"><font color="#ff00ff">0</font></span>)
{
    ++nid;
}

list::~list()
{
    remove();
}

list *list::remove()
{
    <font color="#a52a2a"><b>if</b></font> ( prev ) prev-&gt;next = next;
    <font color="#a52a2a"><b>if</b></font> ( next ) next-&gt;prev = prev;
    next = prev = <span style="background-color: #f2f2f2"><font color="#ff00ff">0</font></span>;
    <font color="#a52a2a"><b>return</b></font> <font color="#a52a2a"><b>this</b></font>;
}

<font color="#2e8b57"><b>void</b></font> list::append( list *lp)
{
    next = lp-&gt;next;
    lp-&gt;next = <font color="#a52a2a"><b>this</b></font>;
    prev = lp;
    <font color="#a52a2a"><b>if</b></font> ( next ) next-&gt;prev = <font color="#a52a2a"><b>this</b></font>;
}

<font color="#2e8b57"><b>void</b></font> list::insert( list *lp)
{
    prev = lp-&gt;prev;
    lp-&gt;prev = <font color="#a52a2a"><b>this</b></font>;
    next = lp;
    <font color="#a52a2a"><b>if</b></font> ( prev ) prev-&gt;next = <font color="#a52a2a"><b>this</b></font>;
}

<font color="#2e8b57"><b>void</b></font> list::print( ostream&amp; os) <font color="#2e8b57"><b>const</b></font>
{
    os &lt;&lt; <span style="background-color: #f2f2f2"><font color="#ff00ff">&quot;[ id = &quot;</font></span> &lt;&lt; id &lt;&lt; <span style="background-color: #f2f2f2"><font color="#ff00ff">&quot; ]&quot;</font></span>;
}

ostream&amp; <font color="#a52a2a"><b>operator</b></font>&lt;&lt;( ostream&amp; os, <font color="#2e8b57"><b>const</b></font> list &amp;l)
{
    l.print(os);
    <font color="#a52a2a"><b>return</b></font> os;
}



</pre>
</body>
</html>
