(window.webpackJsonp=window.webpackJsonp||[]).push([[28],{256:function(e,a,n){"use strict";n.r(a);var r=n(3),t=n(2),l=n(72),d=n(27),o=n(6),w=n(12),s=n(16),c=n(47),i=n(25),m=n(20),h=new r.a({layers:[new o.a({source:new w.b})],target:"map",view:new t.a({center:[0,0],zoom:2})}),u=new s.c({image:new c.a({radius:5,fill:new i.a({color:"yellow"}),stroke:new m.a({color:"red",width:1})})}),p=new s.c({image:new c.a({radius:2,fill:new i.a({color:"blue"})})}),y=new s.c({image:new c.a({radius:5,fill:new i.a({color:"black"})})}),f=2e6;h.on("postcompose",function(e){var a,n=e.vectorContext,r=e.frameState,t=2*Math.PI*r.time/3e4,o=[];for(a=0;a<200;++a){var w=t+2*Math.PI*a/200,s=9e6*Math.cos(w)+2e6*Math.cos(9e6*w/f),c=9e6*Math.sin(w)+2e6*Math.sin(9e6*w/f);o.push([s,c])}n.setStyle(u),n.drawGeometry(new l.a(o));var i=new d.a(o[o.length-1]);n.setStyle(y),n.drawGeometry(i),n.setStyle(p),n.drawGeometry(i),h.render()}),h.render()}},[[256,0]]]);
//# sourceMappingURL=dynamic-data.js.map