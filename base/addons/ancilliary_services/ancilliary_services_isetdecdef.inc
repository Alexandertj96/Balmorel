* Ancillary services by Juan Gea Berm�dez 2019.

SET IASFCRUP(G) "Ancillary service: technology allowed to provide for frequency containment reserves for up regulation";
SET IASAFRRUP(G) "Ancillary service: technology allowed to provide for automatic frequency restoration reserves for up regulation";
SET IASMFRRUP(G) "Ancillary service: technology allowed to provide for manual frequency restoration reserves for up regulation";
SET IASMRRUP(G) "Ancillary service: technology allowed to provide for manual replacement reserves for up regulation";

SET IASFCRDOWN(G) "Ancillary service: technology allowed to provide for frequency containment reserves for down regulation";
SET IASAFRRDOWN(G) "Ancillary service: technology allowed to provide for automatic frequency restoration reserves for down regulation";
SET IASMFRRDOWN(G) "Ancillary service: technology allowed to provide for manual frequency restoration reserves for down regulation";
SET IASMRRDOWN(G) "Ancillary service: technology allowed to provide for manual replacement reserves for down regulation";


*Frequency containment reserves
IASFCRUP(IGUC)$(GDATA(IGUC,'GDUCRAMPU') GE MIN_RAMPING_FCR AND IGKE(IGUC)
$ifi %HYDROGEN%==yes AND NOT(IHYDROGEN_GETOH2(IGUC) OR IHYDROGEN_GETOHH2(IGUC) OR IHYDROGEN_GEHTOH2(IGUC))
)=YES;

IASFCRUP(IGUC)$(GDATA(IGUC,'GDUCRAMPD') GE MIN_RAMPING_FCR AND (IGETOH(IGUC)
$ifi %HYDROGEN%==yes  OR IHYDROGEN_GH2TOBIOMETH(IGUC) OR IHYDROGEN_GBIOGASMETHANATION(IGUC) OR IHYDROGEN_GBIOGASUPGRADING(IGUC) OR IHYDROGEN_GETOH2(IGUC) OR IHYDROGEN_GETOHH2(IGUC) OR IHYDROGEN_GEHTOH2(IGUC)
))=YES;

IASFCRDOWN(IGUC)$(GDATA(IGUC,'GDUCRAMPD') GE MIN_RAMPING_FCR AND IGKE(IGUC)
$ifi %HYDROGEN%==yes AND NOT(IHYDROGEN_GETOH2(IGUC) OR IHYDROGEN_GETOHH2(IGUC) OR IHYDROGEN_GEHTOH2(IGUC))
)=YES;

IASFCRDOWN(IGUC)$(GDATA(IGUC,'GDUCRAMPU') GE MIN_RAMPING_FCR AND (IGETOH(IGUC)
$ifi %HYDROGEN%==yes  OR IHYDROGEN_GH2TOBIOMETH(IGUC) OR IHYDROGEN_GBIOGASMETHANATION(IGUC) OR IHYDROGEN_GBIOGASUPGRADING(IGUC) OR IHYDROGEN_GETOH2(IGUC) OR IHYDROGEN_GETOHH2(IGUC) OR IHYDROGEN_GEHTOH2(IGUC)
))=YES;

*Automatic frequency restoration reserves
IASAFRRUP(IGUC)$(GDATA(IGUC,'GDUCRAMPU') GE MIN_RAMPING_AFRR AND IGKE(IGUC)
$ifi %HYDROGEN%==yes AND NOT(IHYDROGEN_GETOH2(IGUC) OR IHYDROGEN_GETOHH2(IGUC) OR IHYDROGEN_GEHTOH2(IGUC))
)=YES;

IASAFRRUP(IGUC)$(GDATA(IGUC,'GDUCRAMPD') GE MIN_RAMPING_AFRR AND (IGETOH(IGUC)
$ifi %HYDROGEN%==yes  OR IHYDROGEN_GH2TOBIOMETH(IGUC) OR IHYDROGEN_GBIOGASMETHANATION(IGUC) OR IHYDROGEN_GBIOGASUPGRADING(IGUC) OR IHYDROGEN_GETOH2(IGUC) OR IHYDROGEN_GETOHH2(IGUC) OR IHYDROGEN_GEHTOH2(IGUC)
))=YES;

IASAFRRDOWN(IGUC)$(GDATA(IGUC,'GDUCRAMPD') GE MIN_RAMPING_AFRR AND IGKE(IGUC)
$ifi %HYDROGEN%==yes AND NOT(IHYDROGEN_GETOH2(IGUC) OR IHYDROGEN_GETOHH2(IGUC) OR IHYDROGEN_GEHTOH2(IGUC))
)=YES;

IASAFRRDOWN(IGUC)$(GDATA(IGUC,'GDUCRAMPU') GE MIN_RAMPING_AFRR AND (IGETOH(IGUC)
$ifi %HYDROGEN%==yes  OR IHYDROGEN_GH2TOBIOMETH(IGUC) OR IHYDROGEN_GBIOGASMETHANATION(IGUC) OR IHYDROGEN_GBIOGASUPGRADING(IGUC) OR IHYDROGEN_GETOH2(IGUC) OR IHYDROGEN_GETOHH2(IGUC) OR IHYDROGEN_GEHTOH2(IGUC)
))=YES;

*Manual frequency restoration reserves
IASMFRRUP(IGUC)$(GDATA(IGUC,'GDUCRAMPU') GE MIN_RAMPING_MFRR  AND IGKE(IGUC) AND GDATA(IGUC,'GDUCDTMIN') LE MAX_STARTTIME_MFRR
$ifi %HYDROGEN%==yes AND NOT(IHYDROGEN_GETOH2(IGUC) OR IHYDROGEN_GETOHH2(IGUC) OR IHYDROGEN_GEHTOH2(IGUC))
)=YES;

IASMFRRDOWN(IGUC)$(GDATA(IGUC,'GDUCRAMPU') GE MIN_RAMPING_MFRR AND GDATA(IGUC,'GDUCDTMIN') LE MAX_STARTTIME_MFRR AND (IGETOH(IGUC)
$ifi %HYDROGEN%==yes  OR IHYDROGEN_GH2TOBIOMETH(IGUC) OR IHYDROGEN_GBIOGASMETHANATION(IGUC) OR IHYDROGEN_GBIOGASUPGRADING(IGUC) OR IHYDROGEN_GETOH2(IGUC) OR IHYDROGEN_GETOHH2(IGUC) OR IHYDROGEN_GEHTOH2(IGUC)
))=YES;

*Manual replacement reserves
IASMRRUP(IGUC)$(IGKE(IGUC) AND GDATA(IGUC,'GDUCDTMIN') LE MAX_STARTTIME_MRR
$ifi %HYDROGEN%==yes AND NOT(IHYDROGEN_GETOH2(IGUC) OR IHYDROGEN_GETOHH2(IGUC) OR IHYDROGEN_GEHTOH2(IGUC))
)=YES;

IASMRRDOWN(IGUC)$(GDATA(IGUC,'GDUCDTMIN') LE MAX_STARTTIME_MRR AND (IGETOH(IGUC)
$ifi %HYDROGEN%==yes  OR IHYDROGEN_GH2TOBIOMETH(IGUC) OR IHYDROGEN_GBIOGASMETHANATION(IGUC) OR IHYDROGEN_GBIOGASUPGRADING(IGUC) OR IHYDROGEN_GETOH2(IGUC) OR IHYDROGEN_GETOHH2(IGUC) OR IHYDROGEN_GEHTOH2(IGUC)
))=YES;

*Variable production technologies (solar, wind, wave, etc) are not allowed to provide reserves by default
IASFCRUP(IGUC)$(NOT(IGDISPATCH(IGUC)))=NO;
IASAFRRUP(IGUC)$(NOT(IGDISPATCH(IGUC)))=NO;
IASMFRRUP(IGUC)$(NOT(IGDISPATCH(IGUC)))=NO;
IASMRRUP(IGUC)$(NOT(IGDISPATCH(IGUC)))=NO;
IASFCRDOWN(IGUC)$(NOT(IGDISPATCH(IGUC)))=NO;
IASAFRRDOWN(IGUC)$(NOT(IGDISPATCH(IGUC)))=NO;
IASMFRRDOWN(IGUC)$(NOT(IGDISPATCH(IGUC)))=NO;
IASMRRDOWN(IGUC)$(NOT(IGDISPATCH(IGUC)))=NO;


$ifi NOT %ANC_SERV_VRE%==yes $goto NO_ANC_SERV_VRE
*Allowing VRE to provide the following services if selected in balopt.opt
IASFCRUP(G)$(IGHYRR(G)+IGWND(G)+IGSOLE(G)+IGWAVE(G))=YES;
IASAFRRUP(G)$(IGHYRR(G)+IGWND(G)+IGSOLE(G)+IGWAVE(G))=YES;
IASMFRRUP(G)$(IGHYRR(G)+IGWND(G)+IGSOLE(G)+IGWAVE(G))=YES;
IASMRRUP(G)$(IGHYRR(G)+IGWND(G)+IGSOLE(G)+IGWAVE(G))=YES;
IASFCRDOWN(G)$(IGHYRR(G)+IGWND(G)+IGSOLE(G)+IGWAVE(G))=YES;
IASAFRRDOWN(G)$(IGHYRR(G)+IGWND(G)+IGSOLE(G)+IGWAVE(G))=YES;
IASMFRRDOWN(G)$(IGHYRR(G)+IGWND(G)+IGSOLE(G)+IGWAVE(G))=YES;
IASMRRDOWN(G)$(IGHYRR(G)+IGWND(G)+IGSOLE(G)+IGWAVE(G))=YES;
$label NO_ANC_SERV_VRE


$ifi NOT %FCR%==yes  IASFCRUP(G)=NO;
$ifi NOT %AFRR%==yes IASAFRRUP(G)=NO;
$ifi NOT %MFRR%==yes IASMFRRUP(G)=NO;
$ifi NOT %MRR%==yes  IASMRRUP(G)=NO;
$ifi NOT %FCR%==yes  IASFCRDOWN(G)=NO;
$ifi NOT %AFRR%==yes IASAFRRDOWN(G)=NO;
$ifi NOT %MFRR%==yes IASMFRRDOWN(G)=NO;
$ifi NOT %MRR%==yes  IASMRRDOWN(G)=NO;


$ifi %DOWN_REGULATION_INCLUDED%==yes  $goto NO_DOWN_REGULATION_INCLUDED
*Removing down regulation if selected in balopt.opt
IASFCRDOWN(G)=NO;
IASAFRRDOWN(G)=NO;
IASMFRRDOWN(G)=NO;
IASMRRDOWN(G)=NO;
$label NO_DOWN_REGULATION_INCLUDED