pragma solidity >=0.4.22<0.6.0;
//@title授权投票
contract Ballot{
    //声明了一个新的复杂类型，代表单一选民
    struct Voter{
        uint weight;//weight是委托累加
        bool voted;//如果为真，此人已经投票
        address delegate;//代表人的地址
        uint vote;//投票提案索引
    }
    
    //单一提案 
    struct Proposal{
        bytes32 name;//短名称（多达32字节）
        uint voteCount;//累计投票数
    }
    
    address public chairperson;//定义一个变量chairperson,类型是address
    
    //这声明了一个状态变量，它为每个可能的地址存储一个“Voter”结构。
    mapping(address=>Voter) public voters;
    
    //'Proposal'的结构体数组
    Proposal[] public proposals;
    
    //创建一个新的选票来选择一个“proposalNames”
    constructor(bytes32[] memory proposalNames) public{
        chairperson=msg.sender;
        voters[chairperson].weight=1;
        //对于每个提供的提案名称，创建一个新的提案对象并添加它到数组的末尾。
        for(uint i=0;i<proposalNames.length;i++){
            proposals.push(Proposal({
                name:proposalNames[i],
                voteCount:0
            }));
        }
    }
    //只有 ‘chairperson’才可以参加投票
    function giveRightToVote(address voter) public{
        require(
            msg.sender==chairperson,
            "Only chairperson can give right to vote"
            );
        require(
            !voters[voter].voted,
            "The voter already voted."
            );
         voters[voter].weight=1;       
    }
    //把选票投给代表人
    function delegate(address to) public{
        //赋值
        Voter storage sender=voters[msg.sender];
        require(!sender.voted,"You already voted.");
        require(to!=msg.sender,"Self-delegation is disallowed.");
        while(voters[to].delegate!=address(0)){
            to=voters[to].delegate;
            //在授权中发现了一个循环，是不允许的。
            require(to!=msg.sender,"Found loop in delegation");
        }
        sender.voted=true;
        sender.delegate=to;
        Voter storage delegate_=voters[to];
        if(delegate_.voted){
            //如果代表已投票，直接增加票数
            proposals[delegate_.vote].voteCount+=sender.weight;
        }else{
            //如果代表还没有投票，增加他的weight
            delegate_.weight+=sender.weight;
        }
    }
    
    function vote(uint proposal) public{
        Voter storage sender=voters[msg.sender];
        require(!sender.voted,"Already voted.");
        sender.voted=true;
        sender.vote=proposal;
        //如果“提案”超出了数组的范围，这会自动投掷并回复所有变化。
        proposals[proposal].voteCount+=sender.weight;
    }
    //计算所有先前投票的胜诉提案
    function winningProposal() public view returns(uint winningProposal_){
        uint winingVoteCount=0;
        for(uint p=0;p<proposals.length;p++){
            if(proposals[p].voteCount>winingVoteCount){
                winingVoteCount=proposals[p].voteCount;
                winningProposal_=p;
            }
        }
    }
    //调用winningProposal()函数以获取建议数组中包含的获胜者的索引，然后返回获胜者的名称
    function winnerName() public view returns(bytes32 winnerName_){
        winnerName_=proposals[winningProposal()].name;
    }
    
    
    
    
    
    
    

}
