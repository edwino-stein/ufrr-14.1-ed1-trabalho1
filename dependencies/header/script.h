/*
  Definição do javascript da página
  
  Edwino Stein - 1201324411
*/

#define SCRIPT "\n\
<script type=\"text/javascript\" >\n\
    comandos = [*CMDS*];\n\
    app={\n\
        contexto: null,\n\
        pencil: true,\n\
        x: 0,\n\
        y: 0,\n\
        getColor: function(id){\n\
            switch(id){\n\
                case 0:return \'#000\';break;\n\
                case 1:return \'#f00\';break;\n\
                case 2:return \'#0f0\';break;\n\
                case 3:return \'#00f\';break;\n\
                case 4:return \'#ff0\';break;\n\
                case 5:return \'#f0f\';break;\n\
                case 6:return \'#0ff\';break;\n\
                case 7:return \'#fff\';break;\n\
                default:return \'#000\';\n\
            }\n\
        },\n\
        execCmd: function (cmd){\n\
            switch(cmd.statement){\n\
                case \'pd\':this.x += cmd.param;break;\n\
                case \'pe\':this.x -= cmd.param;break;\n\
                case \'pf\':this.y -= cmd.param;break;\n\
                case \'pt\':this.y += cmd.param;break;\n\
                case \'liga\':this.pencil = true;break;\n\
                case \'desliga\':this.pencil = false;break;\n\
                case \'cor\':this.contexto.strokeStyle = this.getColor(cmd.param);return;break;\n\
            }\n\
            if(this.x < 0) this.x = 0;\n\
            if(this.x > 300) this.x = 300;\n\
            if(this.y < 0) this.y = 0;\n\
            if(this.y > 300) this.y = 300;\n\
            if(this.pencil){ this.contexto.lineTo(this.x, this.y); this.contexto.stroke();}\n\
            else{this.contexto.moveTo(this.x, this.y);}\n\
        },\n\
        run: function (cmds){\n\
            this.contexto = document.getElementsByTagName(\'canvas\')[0].getContext(\"2d\");\n\
            this.contexto.strokeStyle = \'#000\';\n\
            this.contexto.moveTo(0, 0);\n\
            for(var i in cmds) this.execCmd(cmds[i]);\n\
        }\n\
    };\n\
    app.run(comandos);\n\
</script>"
