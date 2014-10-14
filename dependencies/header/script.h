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
        angle: 0,\n\
        degreesToRadians: function (angle){\n\
            return angle * (Math.PI/180);\n\
        },\n\
        ajustAngle: function(angle){\n\
            if(angle > 360) while(angle > 360) angle -= 360;\n\
            else if( angle < 0) angle = this.ajustAngle(angle * (-1));\n\
            return angle;\n\
        },\n\
        execCmd: function (cmd){\n\
            switch(cmd.statement){\n\
                case \'ghorario\':\n\
                    this.angle -= this.ajustAngle(cmd.param);\n\
                    if(this.angle < 0) this.angle = 360 + this.angle;\n\
                    return;\n\
                break;\n\
                case \'gantihorario\':\n\
                    this.angle += this.ajustAngle(cmd.param);\n\
                    if(this.angle > 360) this.angle -= 360;\n\
                    return;\n\
                break;\n\
                case \'pfrente\':\n\
                    this.x = this.x + cmd.param * Math.cos(this.degreesToRadians(this.angle));\n\
                    this.y = this.y - cmd.param * Math.sin(this.degreesToRadians(this.angle));\n\
                break;\n\
                case \'ptras\':\n\
                    this.x = this.x - cmd.param * Math.cos(this.degreesToRadians(this.angle));\n\
                    this.y = this.y + cmd.param * Math.sin(this.degreesToRadians(this.angle));\n\
                break;\n\
                case \'ligar\':this.pencil=true;break;\n\
                case \'desligar\':this.pencil=false;break;\n\
            }\n\
            if(this.pencil) this.contexto.lineTo(this.x, this.y);\n\
            else this.contexto.moveTo(this.x, this.y);\n\
        },\n\
        run: function (cmds){\n\
            var canvasEl = document.getElementsByTagName('canvas')[0];\n\
            this.contexto = canvasEl.getContext(\"2d\");\n\
            this.contexto.translate(canvasEl.width/2, canvasEl.height/2);\n\
            this.contexto.strokeStyle = \'#F00\';\n\
            this.contexto.moveTo(this.x, this.y);\n\
            for(var i in cmds) this.execCmd(cmds[i]);\n\
            this.contexto.stroke();\n\
        }\n\
    };\n\
    app.run(comandos);\n\
</script>"
