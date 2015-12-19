<map version="freeplane 1.3.0">
<!--To view this file, download free mind mapping software Freeplane from http://freeplane.sourceforge.net -->
<node TEXT="ma" ID="Freemind_Link_1331878192" CREATED="1266488194781" MODIFIED="1448009872299"><hook NAME="MapStyle">
    <properties show_note_icons="true"/>

<map_styles>
<stylenode LOCALIZED_TEXT="styles.root_node">
<stylenode LOCALIZED_TEXT="styles.predefined" POSITION="right">
<stylenode LOCALIZED_TEXT="default" MAX_WIDTH="600" COLOR="#000000" STYLE="as_parent">
<font NAME="SansSerif" SIZE="10" BOLD="false" ITALIC="false"/>
</stylenode>
<stylenode LOCALIZED_TEXT="defaultstyle.details"/>
<stylenode LOCALIZED_TEXT="defaultstyle.note"/>
<stylenode LOCALIZED_TEXT="defaultstyle.floating">
<edge STYLE="hide_edge"/>
<cloud COLOR="#f0f0f0" SHAPE="ROUND_RECT"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.user-defined" POSITION="right">
<stylenode LOCALIZED_TEXT="styles.topic" COLOR="#18898b" STYLE="fork">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.subtopic" COLOR="#cc3300" STYLE="fork">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.subsubtopic" COLOR="#669900">
<font NAME="Liberation Sans" SIZE="10" BOLD="true"/>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.important">
<icon BUILTIN="yes"/>
</stylenode>
</stylenode>
<stylenode LOCALIZED_TEXT="styles.AutomaticLayout" POSITION="right">
<stylenode LOCALIZED_TEXT="AutomaticLayout.level.root" COLOR="#000000">
<font SIZE="18"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,1" COLOR="#0033ff">
<font SIZE="16"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,2" COLOR="#00b439">
<font SIZE="14"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,3" COLOR="#990000">
<font SIZE="12"/>
</stylenode>
<stylenode LOCALIZED_TEXT="AutomaticLayout.level,4" COLOR="#111111">
<font SIZE="10"/>
</stylenode>
</stylenode>
</stylenode>
</map_styles>
</hook>
<node TEXT="Goal" POSITION="right" ID="Freemind_Link_1242386705" CREATED="1266488217621" MODIFIED="1266488568255" COLOR="#37a3cb">
<node TEXT="build a pomodoro cushion" ID="ID_96158179" CREATED="1447323446878" MODIFIED="1447323460908"/>
</node>
<node TEXT="Plan" POSITION="right" ID="_" CREATED="1266488212530" MODIFIED="1266488546784" COLOR="#373dcb">
<edge COLOR="#808080"/>
<node TEXT="prototype" ID="ID_1781400744" CREATED="1447323464286" MODIFIED="1447323470179"/>
<node TEXT="develop with mark" ID="ID_74517266" CREATED="1447323470630" MODIFIED="1447323475459"/>
<node TEXT="test market alpha version" ID="ID_301781990" CREATED="1447323476190" MODIFIED="1447323483684">
<node TEXT="Sheepsters" ID="ID_387366685" CREATED="1447323484958" MODIFIED="1447323487900"/>
<node TEXT="Makerbiz" ID="ID_275970641" CREATED="1447323488342" MODIFIED="1447323493300"/>
</node>
</node>
<node TEXT="Tasks" POSITION="right" ID="Freemind_Link_857865306" CREATED="1266488223477" MODIFIED="1266488636684" COLOR="#de5613">
<node TEXT="Iteration 1" ID="ID_1251759318" CREATED="1447323501718" MODIFIED="1447498672933">
<node TEXT="prototype" ID="ID_1292865376" CREATED="1447323522102" MODIFIED="1447323584110">
<node TEXT="poc on Arduino" ID="ID_1472007324" CREATED="1447323540526" MODIFIED="1447323545787"/>
<node TEXT="prototype with trinket" ID="ID_992091018" CREATED="1447323550174" MODIFIED="1447323564131"/>
<node TEXT="on breadboard" ID="ID_1968243911" CREATED="1447323564686" MODIFIED="1447323569779"/>
<node TEXT="demo to Mark" ID="ID_1742197195" CREATED="1447323588272" MODIFIED="1447323607691"/>
</node>
<node TEXT="perma-proto" ID="ID_866525343" CREATED="1447498649944" MODIFIED="1447693953697">
<icon BUILTIN="button_ok"/>
</node>
</node>
<node TEXT="Iteration 2" ID="ID_74668136" CREATED="1447831331380" MODIFIED="1447831336827">
<node TEXT="add vibrator" ID="ID_611009538" CREATED="1447831347124" MODIFIED="1448010627378">
<icon BUILTIN="button_ok"/>
<node TEXT="control via software" ID="ID_1488919958" CREATED="1447915629709" MODIFIED="1447915640153"/>
</node>
<node TEXT="measure current" ID="ID_431641340" CREATED="1447831433948" MODIFIED="1450020241901">
<icon BUILTIN="button_ok"/>
<richcontent TYPE="NOTE">

<html>
  <head>
    
  </head>
  <body>
    <p>
      38 -81 ma; the latter when the vibrating disc is running.
    </p>
  </body>
</html>
</richcontent>
<node TEXT="solder" ID="ID_390924412" CREATED="1447836876350" MODIFIED="1447836881691"/>
<node TEXT="test" ID="ID_1560917837" CREATED="1447836882630" MODIFIED="1447836887987"/>
</node>
<node TEXT="add timing to software" ID="ID_1803964188" CREATED="1447915667348" MODIFIED="1447915685842">
<node TEXT="EventBuffer passes tests" ID="ID_793481674" CREATED="1450019042359" MODIFIED="1450451968585">
<icon BUILTIN="button_ok"/>
<node TEXT="set up tests" ID="ID_1570773791" CREATED="1450083823637" MODIFIED="1450171375141">
<node TEXT="create directory in PyCharm" ID="ID_1039844135" CREATED="1450171049286" MODIFIED="1450171384467"/>
<node TEXT="symlink from Arduino" ID="ID_766562825" CREATED="1450171032886" MODIFIED="1450171047475"/>
<node TEXT="create EventBuffer.ino in Arduino" ID="ID_1738348902" CREATED="1450171087342" MODIFIED="1450171113307"/>
<node TEXT="create EventBuffer.cpp, .h in Arduino" ID="ID_1614071940" CREATED="1450171124198" MODIFIED="1450171166219"/>
</node>
<node TEXT="write tests" ID="ID_1538927739" CREATED="1450083845294" MODIFIED="1450083852970"/>
<node TEXT="get tests to pass" ID="ID_1760844462" CREATED="1450083862526" MODIFIED="1450083867730"/>
</node>
<node TEXT="make into library" ID="ID_1051950950" CREATED="1450083853797" MODIFIED="1450083859601"/>
<node TEXT="Tick adds event to Buffer" ID="ID_935953160" CREATED="1450019052975" MODIFIED="1450083879089"/>
<node TEXT="Interrupts add events to buffer" ID="ID_898539758" CREATED="1450019071679" MODIFIED="1450019120924"/>
<node TEXT="measure sleeping current" ID="ID_1154276162" CREATED="1450019125959" MODIFIED="1450019133492"/>
</node>
<node TEXT="fritzing" ID="ID_376526664" CREATED="1447598010754" MODIFIED="1447598023317">
<node TEXT="fritz as is" ID="ID_1985881839" CREATED="1447693960711" MODIFIED="1447744269872">
<icon BUILTIN="button_ok"/>
</node>
<node TEXT="add vibrator + motor controller circuit" ID="ID_47748917" CREATED="1447924790088" MODIFIED="1447924809004"/>
<node TEXT="design piezo component" ID="ID_1883438242" CREATED="1447598024656" MODIFIED="1447598097101">
<node TEXT="use tutorials" ID="ID_468870356" CREATED="1447744273187" MODIFIED="1447744281809">
<node TEXT="review" ID="ID_470976310" CREATED="1447744283130" MODIFIED="1447744287056"/>
<node TEXT="map component creation process" ID="ID_1386678024" CREATED="1447744287538" MODIFIED="1447744470855">
<arrowlink SHAPE="CUBIC_CURVE" COLOR="#000000" WIDTH="2" TRANSPARENCY="80" FONT_SIZE="9" FONT_FAMILY="SansSerif" DESTINATION="ID_797352756" STARTINCLINATION="40;54;" ENDINCLINATION="154;19;" STARTARROW="NONE" ENDARROW="DEFAULT"/>
</node>
</node>
<node TEXT="process" ID="ID_797352756" CREATED="1447744322850" MODIFIED="1447744327976">
<node TEXT="find part to copy" ID="ID_1086355087" CREATED="1447842662976" MODIFIED="1447842674725"/>
<node TEXT="6 areas to change" ID="ID_571176695" CREATED="1447842675336" MODIFIED="1447842679733"/>
<node TEXT="save as new part" ID="ID_121063996" CREATED="1447842680568" MODIFIED="1447842706381"/>
<node TEXT="create new svg" ID="ID_1239860479" CREATED="1447842746800" MODIFIED="1447842755901">
<node TEXT="in Inkscape" ID="ID_1985136903" CREATED="1447842758112" MODIFIED="1447842780949"/>
<node TEXT="same size as your part" ID="ID_786080706" CREATED="1447842763960" MODIFIED="1447842775173"/>
<node TEXT="good name" ID="ID_1093805480" CREATED="1447842810224" MODIFIED="1447842815909">
<node TEXT="one of three" ID="ID_493378701" CREATED="1447842817416" MODIFIED="1447842821669"/>
</node>
</node>
</node>
</node>
</node>
</node>
<node TEXT="Evo" ID="ID_1072635481" CREATED="1447323620822" MODIFIED="1447323631907">
<node TEXT="define qualities" ID="ID_566517839" CREATED="1447323633823" MODIFIED="1447323650099"/>
<node TEXT="iterate designs" ID="ID_1096850209" CREATED="1447323652311" MODIFIED="1447323661371"/>
<node TEXT="release alpha version" ID="ID_180337420" CREATED="1447323664118" MODIFIED="1447323675643"/>
</node>
</node>
<node TEXT="Review" POSITION="left" ID="Freemind_Link_1153466861" CREATED="1266488259116" MODIFIED="1266488895851" COLOR="#fb1802">
<icon BUILTIN="xmag"/>
<node TEXT="WW" ID="Freemind_Link_1466796877" CREATED="1266488965666" MODIFIED="1296303686570" COLOR="#ffcc00" BACKGROUND_COLOR="#006666">
<icon BUILTIN="button_ok"/>
<node TEXT="fritzing" ID="ID_331291263" CREATED="1447498528557" MODIFIED="1447498552306">
<node TEXT="trinket" ID="ID_1260900435" CREATED="1447498553573" MODIFIED="1447498556018"/>
<node TEXT="force-sensitive resistor" ID="ID_803926088" CREATED="1447498556437" MODIFIED="1447498637373"/>
</node>
</node>
<node TEXT="WDNW" ID="Freemind_Link_1910608691" CREATED="1266488980018" MODIFIED="1296303689746">
<icon BUILTIN="button_cancel"/>
<node TEXT="pomodoro.cc" ID="ID_319236748" CREATED="1447498571797" MODIFIED="1447498591594"/>
<node TEXT="soldering Adafruit USB power monitor" ID="ID_1411898546" CREATED="1447840672479" MODIFIED="1447840683292">
<node TEXT="one connector upside down" ID="ID_700773781" CREATED="1447840684775" MODIFIED="1447840704189">
<icon BUILTIN="smily_bad"/>
</node>
</node>
<node TEXT="using battery line to power motor" ID="ID_1184105128" CREATED="1447926035784" MODIFIED="1447926052533">
<node TEXT="can&apos;t use with USB!" ID="ID_1767033216" CREATED="1447926055320" MODIFIED="1447926063253"/>
</node>
</node>
<node TEXT="WDD" ID="Freemind_Link_1294877740" CREATED="1266488984697" MODIFIED="1296303577864" COLOR="#00cc00">
<icon BUILTIN="licq"/>
<node TEXT="colour code =batt, +5v differently" ID="ID_766347329" CREATED="1447926073328" MODIFIED="1447926088117"/>
<node TEXT="need more heat shrink colours" ID="ID_444465284" CREATED="1447926093384" MODIFIED="1447926108517"/>
</node>
<node TEXT="Questions" ID="Freemind_Link_1003502265" CREATED="1266489024048" MODIFIED="1296303570801" COLOR="#00cccc">
<icon BUILTIN="help"/>
</node>
<node TEXT="Surprises" ID="Freemind_Link_19217072" CREATED="1266489032944" MODIFIED="1296303119998" COLOR="#ff0000" BACKGROUND_COLOR="#ffff00">
<icon BUILTIN="messagebox_warning"/>
</node>
<node TEXT="Feelings" ID="Freemind_Link_1706517660" CREATED="1266489043119" MODIFIED="1296303692921" COLOR="#cc0000">
<icon BUILTIN="ksmiletris"/>
</node>
<node TEXT="Ideas" ID="Freemind_Link_1517433488" CREATED="1266488273147" MODIFIED="1266488921179" COLOR="#36d12a">
<icon BUILTIN="idea"/>
<node TEXT="use Discourse?" ID="ID_1051644185" CREATED="1447497222757" MODIFIED="1447498480288" LINK="http://www.discourse.org/"/>
<node TEXT="clever cushion" ID="ID_468986496" CREATED="1447916457260" MODIFIED="1447916470857"/>
<node TEXT="connected cushion" ID="ID_637707558" CREATED="1447916471660" MODIFIED="1447916480849"/>
</node>
<node TEXT="Fridge" ID="Freemind_Link_1954142386" CREATED="1266488793745" MODIFIED="1266488959040" COLOR="#9679df">
<icon BUILTIN="desktop_new"/>
<node TEXT="self-powering, like powerup cushion" ID="ID_212132934" CREATED="1447490748376" MODIFIED="1447490760713"/>
<node TEXT="wifi" ID="ID_614530534" CREATED="1447496813540" MODIFIED="1447496816641"/>
</node>
</node>
<node TEXT="Record" POSITION="left" ID="Freemind_Link_813012694" CREATED="1266488248876" MODIFIED="1266488728945" COLOR="#27444b">
<icon BUILTIN="pencil"/>
</node>
<node TEXT="Resources" POSITION="left" ID="Freemind_Link_1594441695" CREATED="1273319832507" MODIFIED="1296303609303" COLOR="#33ff33">
<icon BUILTIN="password"/>
<node TEXT="marketing" ID="ID_1877720464" CREATED="1447841800495" MODIFIED="1447841817789">
<node TEXT="producthunt" ID="ID_1919064263" CREATED="1447490716059" MODIFIED="1447841833151" LINK="https://www.producthunt.com/tech"/>
<node TEXT="40daystartup" ID="ID_634897571" CREATED="1447491142584" MODIFIED="1447841842910" LINK="https://40daystartup.com/idea-to-launch?ref=producthunt"/>
<node TEXT="tools apps to better manage your blog" ID="ID_1833350403" CREATED="1447508701271" MODIFIED="1447841889950" LINK="http://www.socialmediaexaminer.com/tools-apps-to-better-manage-your-blog-ian-cleary/"/>
</node>
<node TEXT="CE, EMC, FCC cert" ID="ID_80343705" CREATED="1447508794012" MODIFIED="1447508821550" LINK="http://www.batteryspace.com/ul-ce-emc-fcc-and-csa.aspx"/>
<node TEXT="User experiences" ID="ID_656655085" CREATED="1447511261391" MODIFIED="1447511269920"/>
<node TEXT="pomodoro" ID="ID_629826291" CREATED="1447511925186" MODIFIED="1447511928847">
<node TEXT="pomodoro website" ID="ID_1087496525" CREATED="1447511828970" MODIFIED="1447511869601" LINK="http://pomodorotechnique.com/">
<node TEXT="book" ID="ID_709905142" CREATED="1447511733354" MODIFIED="1447511785552" LINK="resources/books/ThePomodoroTechnique_v1-3.pdf"/>
<node TEXT="cheat sheet" ID="ID_1732638231" CREATED="1447511875426" MODIFIED="1447511902353" LINK="resources/articles/pomodoro_cheat_sheet.pdf"/>
</node>
<node TEXT="http://www.lifehack.org/articles/productivity/the-pomodoro-technique-is-it-right-for-you.html" ID="ID_231988112" CREATED="1447511934307" MODIFIED="1447511934307" LINK="http://www.lifehack.org/articles/productivity/the-pomodoro-technique-is-it-right-for-you.html"/>
<node TEXT="http://www.infoq.com/news/2010/02/pomodoro-critique#anch53535" ID="ID_1015885706" CREATED="1447511294002" MODIFIED="1447511294002" LINK="http://www.infoq.com/news/2010/02/pomodoro-critique#anch53535"/>
<node TEXT="http://productivityist.com/the-problem-with-the-pomodoro-technique/" ID="ID_1848446073" CREATED="1447511984892" MODIFIED="1447511984892" LINK="http://productivityist.com/the-problem-with-the-pomodoro-technique/"/>
<node TEXT="http://jan.tomka.name/blog/pomodoro-technique-pros-and-cons" ID="ID_765857704" CREATED="1447522018374" MODIFIED="1447522018374" LINK="http://jan.tomka.name/blog/pomodoro-technique-pros-and-cons"/>
<node TEXT="https://blog.afoolishmanifesto.com/posts/the-pomodoro-technique/" ID="ID_718098510" CREATED="1447522170896" MODIFIED="1447522170896" LINK="https://blog.afoolishmanifesto.com/posts/the-pomodoro-technique/"/>
<node TEXT="http://www.jaeminyi.com/pomodoro/" ID="ID_642787969" CREATED="1447522309509" MODIFIED="1447522309509" LINK="http://www.jaeminyi.com/pomodoro/"/>
</node>
<node TEXT="health" ID="ID_46663606" CREATED="1447512717147" MODIFIED="1447512720951">
<node TEXT="http://www.nhs.uk/livewell/fitness/pages/sitting-and-sedentary-behaviour-are-bad-for-your-health.aspx" ID="ID_1616972459" CREATED="1447512726202" MODIFIED="1447512726202" LINK="http://www.nhs.uk/livewell/fitness/pages/sitting-and-sedentary-behaviour-are-bad-for-your-health.aspx"/>
<node TEXT="http://www.nhs.uk/news/2012/10October/Pages/Having-desk-job-doubles-risk-of-heart-attack.aspx" ID="ID_351969102" CREATED="1447512820353" MODIFIED="1447512820353" LINK="http://www.nhs.uk/news/2012/10October/Pages/Having-desk-job-doubles-risk-of-heart-attack.aspx"/>
<node TEXT="18-64 guidleines (au)" ID="ID_396056191" CREATED="1447520632270" MODIFIED="1447520914874" LINK="resources/articles/brochure%20PA%20Guidelines_A5_18-64yrs.PDF"/>
<node TEXT="take a break -  it could save your life" ID="ID_1084359370" CREATED="1447520937070" MODIFIED="1447520981165" LINK="http://www.independent.co.uk/life-style/health-and-families/health-news/take-a-break-it-could-save-your-life-1872147.html"/>
<node TEXT="https://www.bhf.org.uk/heart-matters-magazine/activity/sitting-down" ID="ID_338852487" CREATED="1447521041087" MODIFIED="1447521041087" LINK="https://www.bhf.org.uk/heart-matters-magazine/activity/sitting-down"/>
<node TEXT="http://www.ncbi.nlm.nih.gov/pmc/articles/PMC3404815/" ID="ID_1461298293" CREATED="1447521068201" MODIFIED="1447521068201" LINK="http://www.ncbi.nlm.nih.gov/pmc/articles/PMC3404815/">
<node TEXT="local copy" ID="ID_1483478486" CREATED="1447521071373" MODIFIED="1447521134917" LINK="resources/articles/nihms229379.pdf"/>
</node>
<node TEXT="acsm brochure" ID="ID_251767792" CREATED="1447521365214" MODIFIED="1447521397782" LINK="resources/articles/reducing-sedentary-behaviors-sitting-less-and-moving-more.pdf"/>
<node TEXT="http://www.npr.org/2011/04/25/135575490/sitting-all-day-worse-for-you-than-you-might-think" ID="ID_1757382130" CREATED="1447521489408" MODIFIED="1447521489408" LINK="http://www.npr.org/2011/04/25/135575490/sitting-all-day-worse-for-you-than-you-might-think"/>
<node TEXT="http://journals.lww.com/acsm-msse/Fulltext/2010/05000/Sedentary_Behaviors_Increase_Risk_of.6.aspx" ID="ID_668248535" CREATED="1447521528658" MODIFIED="1447521528658" LINK="http://journals.lww.com/acsm-msse/Fulltext/2010/05000/Sedentary_Behaviors_Increase_Risk_of.6.aspx">
<node TEXT="local copy" ID="ID_1987357879" CREATED="1447521533646" MODIFIED="1447521575052" LINK="resources/articles/Sedentary_Behaviors_Increase_Risk_of.6.pdf"/>
</node>
<node TEXT="http://lifehacker.com/5879536/how-sitting-all-day-is-damaging-your-body-and-how-you-can-counteract-it" ID="ID_145894311" CREATED="1447521672115" MODIFIED="1447521672115" LINK="http://lifehacker.com/5879536/how-sitting-all-day-is-damaging-your-body-and-how-you-can-counteract-it"/>
</node>
<node TEXT="marketing" ID="ID_576152629" CREATED="1447522788542" MODIFIED="1447522792203">
<node TEXT="landing page" ID="ID_614079794" CREATED="1447522797038" MODIFIED="1447522821437" LINK="resources/images/2-betterUX-large-preview-opt.jpg">
<node TEXT="v2" ID="ID_307786465" CREATED="1447522892710" MODIFIED="1447522908685" LINK="resources/images/5-betterUX-large-preview-opt.jpg"/>
</node>
<node TEXT="http://www.smashingmagazine.com/2014/04/a-guide-to-validating-product-ideas-with-quick-and-simple-experiments/" ID="ID_561453765" CREATED="1447523095426" MODIFIED="1447523095426" LINK="http://www.smashingmagazine.com/2014/04/a-guide-to-validating-product-ideas-with-quick-and-simple-experiments/"/>
<node TEXT="fiverr crowdfunding animation" ID="ID_757160903" CREATED="1447598905789" MODIFIED="1447598944966" LINK="https://uk.fiverr.com/elbgal/produce-a-crowdfunding-campaign-video?context=advanced_search&amp;context_type=auto&amp;context_referrer=search_gigs&amp;source=top-bar&amp;pos=40&amp;funnel=7715096a-8d10-4f21-8ad4-ca4b83d420f0"/>
</node>
<node TEXT="fritzing" ID="ID_219295323" CREATED="1447745810298" MODIFIED="1447745814432">
<node TEXT="tutorials" ID="ID_501227452" CREATED="1447598210688" MODIFIED="1447745824960">
<node TEXT="sparkfun: make your own fritzing parts" ID="ID_430265017" CREATED="1447744579124" MODIFIED="1447744623833" LINK="https://learn.sparkfun.com/tutorials/make-your-own-fritzing-parts"/>
<node TEXT="authoring svg with a text editor" ID="ID_1125332835" CREATED="1447598289855" MODIFIED="1447744523107" LINK="http://weblogs.asp.net/bleroy/authoring-svg-with-a-text-editor"/>
<node TEXT="making a part in fritzing" ID="ID_1309477082" CREATED="1447744652711" MODIFIED="1447744681065" LINK="http://jacobfenwick.com/making-a-part-in-fritzing-0-8-7b/"/>
<node TEXT="making smd fritzing part" ID="ID_1883500361" CREATED="1447744748932" MODIFIED="1447744777185" LINK="https://plashless.wordpress.com/2012/09/07/making_smd_fritzingpart/"/>
</node>
<node TEXT="standards" ID="ID_1656469475" CREATED="1447745826050" MODIFIED="1447745830144">
<node TEXT="fritzings graphic standards" ID="ID_1264067458" CREATED="1447842036022" MODIFIED="1447842049902" LINK="http://fritzing.org/fritzings-graphic-standards/"/>
<node TEXT="download fonts and templates" ID="ID_1012869687" CREATED="1447842395778" MODIFIED="1447842413294" LINK="http://fritzing.org/learning/tutorials/creating-custom-parts/download-fonts-and-templates/"/>
<node TEXT="https://github.com/fritzing/fritzing-app/wiki/2.1-Part-file-format" ID="ID_1392234902" CREATED="1447842447207" MODIFIED="1447842447207" LINK="https://github.com/fritzing/fritzing-app/wiki/2.1-Part-file-format"/>
</node>
</node>
<node TEXT="Tasker" ID="ID_718404562" CREATED="1448727139120" MODIFIED="1448727145954">
<node TEXT="UML state machine" ID="ID_1432960996" CREATED="1448727423385" MODIFIED="1448727498304" LINK="https://en.wikipedia.org/wiki/UML_state_machine"/>
<node TEXT="Build a Super Simple Tasker" ID="ID_150892234" CREATED="1448727466033" MODIFIED="1448727520352" LINK="http://www.embedded.com/design/prototyping-and-development/4025691/Build-a-Super-Simple-Tasker"/>
<node TEXT="QL/QM/QP" ID="ID_447010" CREATED="1448792054802" MODIFIED="1448891470355">
<node TEXT="http://playground.arduino.cc/Code/QP" ID="ID_130897889" CREATED="1448792070346" MODIFIED="1448792070346" LINK="http://playground.arduino.cc/Code/QP"/>
<node TEXT="QP/Arduino tutorial" ID="ID_259095911" CREATED="1448792798866" MODIFIED="1448792866392" LINK="../../../Dropbox/resources/articles/AN_Event-Driven_Arduino-1.6.x.pdf"/>
<node TEXT="QP: Romilly&apos;s checklist" ID="ID_168305762" CREATED="1448891472984" MODIFIED="1448891497616">
<node TEXT="Define model" ID="ID_170305933" CREATED="1448891626264" MODIFIED="1448891633293"/>
<node TEXT="Write code" ID="ID_8959502" CREATED="1448891635312" MODIFIED="1448891642062"/>
</node>
</node>
</node>
</node>
<node TEXT="issues" POSITION="right" ID="ID_42575275" CREATED="1447499593501" MODIFIED="1447499596469">
<node TEXT="forget to start" ID="ID_635753030" CREATED="1447499598022" MODIFIED="1447499603946"/>
<node TEXT="reset when I get up" ID="ID_140881226" CREATED="1447499604454" MODIFIED="1447499609810"/>
<node TEXT="can&apos;t hear" ID="ID_276209016" CREATED="1447499610382" MODIFIED="1447597995837"/>
</node>
</node>
</map>
