(window.webpackJsonp=window.webpackJsonp||[]).push([[30],{258:function(e,a,t){"use strict";t.r(a);var s,n=t(3),r=t(2),o=t(105),c=t(37),w=t(22),i=t(6),l=t(208),m=t(83),u=t(15),p=t(16),g=t(25),b=t(20),d=t(100),f=[[0,0],[4,2],[6,0],[10,5],[6,3],[4,5],[0,0]],k=function(e){return[e[0]*s,e[1]*s]},v={},y=new w.a({source:new u.a({url:"data/kml/2012_Earthquakes_Mag5.kml",format:new o.a({extractStyles:!1})}),style:function(e){var a=e.get("name"),t=parseFloat(a.substr(2)),n=parseInt(10+40*(t-5),10);s=n/10;var r=v[n];if(!r){var o=document.createElement("canvas"),w=Object(l.a)(o.getContext("2d"),{size:[n,n],pixelRatio:1});w.setStyle(new p.c({fill:new g.a({color:"rgba(255, 153, 0, 0.4)"}),stroke:new b.a({color:"rgba(255, 204, 0, 0.2)",width:2})})),w.drawGeometry(new c.b([f.map(k)])),r=new p.c({image:new d.a({img:o,imgSize:[n,n],rotation:1.2})}),v[n]=r}return r}}),h=new i.a({source:new m.a({layer:"toner"})});new n.a({layers:[h,y],target:"map",view:new r.a({center:[0,0],zoom:2})})}},[[258,0]]]);
//# sourceMappingURL=earthquake-custom-symbol.js.map